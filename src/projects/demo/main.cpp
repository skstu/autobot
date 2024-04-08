#include "stdafx.h"

static std::string __gp_current_prodir;
static std::map<Key, Types> __gp_map_object;
static std::map<Key, Types> __gp_map_operator;
static std::map<Key, Types> __gp_map_action;
static int load_interface();
static int load_template();

int main(int argc, char* argv[]) {
	char szPath[MAX_PATH];
	DWORD dwRet = GetModuleFileNameA(GetModuleHandleA(NULL), szPath, MAX_PATH);
	char* fch = strrchr(szPath, '\\');
	if (!fch) {
		fch = strrchr(szPath, '/');
	}
	fch++;
	fch[0] = 0;
	__gp_current_prodir = szPath;

	load_interface();
	load_template();

	return 0;
}

/*
{
	"type": 6,
	"action": 1,
	"operator": 9,
	"objects": [
		{
			"comment":"player choice",
			"type": 6,
			"value": 1
		},
		{
			"comment":"robot choice",
			"type": 6,
			"value": 3
		}
	]
}

import random

user_choice = int(input("请选择（0石头/1剪刀/2布）："))
computer_choice = random.randint(0, 2)

print("你的选择：")

if user_choice==0:
	print("石头")
else:
	if user_choice==1:
		print("剪刀")
	else:
		 print("布")
print("计算机的选择：")
if computer_choice==0:
	print("石头")
else:
	if computer_choice==1:
		print("剪刀")
	else:
		 print("布")

if user_choice == computer_choice:
	print("平局！")
else:
	if (user_choice == 0 and computer_choice == 1) or \
		(user_choice == 1 and computer_choice == 2) or \
		(user_choice == 2 and computer_choice == 0):
		print( "你赢了！")
	else:
		print( "计算机赢了！")

*/

int load_interface() {
	int result = 0;
	do {
		std::string file_buffer = stl::File::ReadFile(__gp_current_prodir + "/../../../../doc/接口定义.json");
		if (file_buffer.empty())
			break;
		rapidjson::Document doc;
		if (doc.Parse(file_buffer.data(), file_buffer.size()).HasParseError())
			break;

		do {//!@ Parser operator
			if (!doc.HasMember("operator") || !doc["operator"].IsArray())
				break;
			rapidjson::Value& ayOperator = doc["operator"];
			for (rapidjson::Value* it = ayOperator.Begin(); it != ayOperator.End(); ++it) {
				if (!it->HasMember("name") || !it->HasMember("symbol") || !it->HasMember("key"))
					continue;
				rapidjson::Value& theObj = *it;
				if (!theObj["name"].IsString() || !theObj["symbol"].IsString() || !theObj["key"].IsUint())
					continue;
				Types op;
				op.key = theObj["key"].GetUint();
				op.name = theObj["name"].GetString();
				op.symbol = theObj["name"].GetString();

				auto exists = __gp_map_operator.find(op.key);
				if (exists != __gp_map_operator.end())
					__gp_map_operator.erase(exists);
				__gp_map_operator.emplace(op.key, op);
			}
		} while (0);

		do {//!@ Parser action
			if (!doc.HasMember("action") || !doc["action"].IsArray())
				break;
			rapidjson::Value& ayAction = doc["action"];
			for (rapidjson::Value* it = ayAction.Begin(); it != ayAction.End(); ++it) {
				if (!it->HasMember("name") || !it->HasMember("symbol") || !it->HasMember("key"))
					continue;
				rapidjson::Value& theObj = *it;
				if (!theObj["name"].IsString() || !theObj["symbol"].IsString() || !theObj["key"].IsUint())
					continue;
				Types op;
				op.key = theObj["key"].GetUint();
				op.name = theObj["name"].GetString();
				op.symbol = theObj["name"].GetString();

				auto exists = __gp_map_action.find(op.key);
				if (exists != __gp_map_action.end())
					__gp_map_action.erase(exists);
				__gp_map_action.emplace(op.key, op);
			}
		} while (0);

		do {//!@ Parser types
			if (!doc.HasMember("object") || !doc["object"].IsArray())
				break;
			rapidjson::Value& ayTypes = doc["object"];
			for (rapidjson::Value* it = ayTypes.Begin(); it != ayTypes.End(); ++it) {
				if (!it->HasMember("name") || !it->HasMember("key"))
					continue;
				rapidjson::Value& theObj = *it;
				if (!theObj["name"].IsString() || !theObj["key"].IsUint())
					continue;
				Types type;
				type.symbol = "";
				type.key = theObj["key"].GetUint();
				type.name = theObj["name"].GetString();

				auto exists = __gp_map_object.find(type.key);
				if (exists != __gp_map_object.end())
					__gp_map_object.erase(exists);
				__gp_map_object.emplace(type.key, type);
			}
		} while (0);
		result = 1;
	} while (0);
	return result;
}

/*
{
	"type": 6,
	"name":"result",
	"action": 1,
	"operator": 9,
	"objects": [
		{
			"comment":"player choice",
			"name":"player_choice",
			"type": 6,
			"value": 1
		},
		{
			"comment":"robot choice",
			"name":"robot_choice",
			"type": 6,
			"value": 3
		}
	]
}
*/
int load_template() {
	int result = 0;
	do {
		std::string file_buffer = stl::File::ReadFile(__gp_current_prodir + "/../../../../doc/数据模板.json");
		if (file_buffer.empty())
			break;
		Object finalObj;
		if (!(finalObj << file_buffer))
			break;

		switch (finalObj.operator_) {
		case OperatorType::EQ: {

		}break;
		case OperatorType::AND: {

		}break;
		case OperatorType::OR: {

		}break;
		default:
			break;
		}


		result = 1;
	} while (0);
	return result;
}