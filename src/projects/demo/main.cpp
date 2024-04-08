#include <iostream>
#include <stl.h>
#include <rapidjson.h>
#include <Windows.h>

using Key = int;

class Types {//!@ 类型
public:
	Key key = 0;
	std::string symbol;
	std::string name;
};

enum class OperatorType : Key {
	UNKNOWN = 0,
	AND = 1,
	OR = 2,
	NOT = 3,
	ADD = 4,
	SUB = 5,
	MUL = 6,
	DIV = 7,
	MOD = 8,
	EQ = 9,
	NE = 0xA,
	GT = 0xB,
	LT = 0xC,
	GE = 0xD,
	LE = 0xE,
};
enum class ObjectType : Key {
	UNKNOWN = 0,
	BOOLEAN = 1,
	FLOAT = 2,//!@ 浮点型对象
	DATA = 3, //!@ 数据对象 json(object)
	OPERATOR = 4,//!@ 运算符对象
	STRING = 5,//!@ 字符串对象
	INTEGER = 6,//!@ 整型对象
};
static int load_interface();
static int load_template();

class Object {//!@ 对象
public:
	class Condition {
	public:
	};
public:
	ObjectType object_type_;
	OperatorType operator_type_;
	std::string name_;
	std::string symbol_;
};


static std::string __gp_current_prodir;
static std::map<Key, Types> __gp_map_object;
static std::map<Key, Types> __gp_map_operator;
int main(int argc, char* argv[]) {
	char szPath[MAX_PATH];
	DWORD dwRet = GetModuleFileNameA(GetModuleHandle(NULL), szPath, MAX_PATH);
	char* fch = strrchr(szPath, '\\');
	if (!fch) {
		fch = strrchr(szPath, '/');
	}
	fch++;
	fch[0] = 0;
	__gp_current_prodir = szPath;

	load_interface();
	load_template();

	do {





	} while (0);




	return 0;
}



int load_interface() {
	int result = 0;
	do {
		std::string file_buffer = stl::File::ReadFile(__gp_current_prodir + "interface.json");
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
int load_template() {
	int result = 0;
	do {

	} while (0);
	return result;
}