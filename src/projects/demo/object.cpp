#include "stdafx.h"

Object::Object() {


}

Object::~Object() {

}
bool Object::operator<<(const std::string& json_data) {
	bool result = false;
	do {
		if (json_data.empty())
			break;
		rapidjson::Document doc;
		if (doc.Parse(json_data.data(), json_data.size()).HasParseError())
			break;
		if (doc.HasMember("type") && doc["type"].IsUint()) {
			type_ = static_cast<ObjectType>(doc["type"].GetUint());
		}
		if (doc.HasMember("action") && doc["action"].IsUint()) {
			action_ = static_cast<ActionType>(doc["action"].GetUint());
		}
		if (doc.HasMember("operator") && doc["operator"].IsUint()) {
			operator_ = static_cast<OperatorType>(doc["operator"].GetUint());
		}
		if (doc.HasMember("comment") && doc["comment"].IsString()) {
			comment_ = doc["comment"].GetString();
		}
		if (doc.HasMember("value") && doc["value"].IsString()) {
			value_ = doc["value"].GetString();
		}
		if (doc.HasMember("objects") && doc["objects"].IsArray()) {
			rapidjson::Value& ayObj = doc["objects"];
			for (auto it = ayObj.Begin(); it != ayObj.End(); ++it) {
				if (!it->IsObject())
					continue;
				Object obj;
				std::string jsonStr = shared::Json::toString(*it);
				if (jsonStr.empty())
					continue;
				if (!(obj << jsonStr))
					continue;
				objects_.push_back(obj);
			}
		}
		result = true;
	} while (0);
	return result;
}