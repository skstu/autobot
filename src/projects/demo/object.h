#pragma once

class Object {//!@ ∂‘œÛ
public:
	Object();
	~Object();
public:
	ObjectType type_;
	ActionType action_;
	OperatorType operator_;
	std::string name_;
	std::string symbol_;
	std::string value_;
	std::string comment_;
	std::vector<Object> objects_;
public:
	bool operator<<(const std::string& json_data);
	void operator=(const Object& obj) {
		type_ = obj.type_;
		action_ = obj.action_;
		operator_ = obj.operator_;
		name_ = obj.name_;
		symbol_ = obj.symbol_;
		objects_ = obj.objects_;
		value_ = obj.value_;
		comment_ = obj.comment_;

	}
	bool operator!=(const Object& obj) const {
		return !(*this == obj);
	}
	bool operator==(const Object& obj) const {
		bool result = false;
		do {
			if (type_ != obj.type_)
				break;
			if (action_ != obj.action_)
				break;
			if (operator_ != obj.operator_)
				break;
			if (name_ != obj.name_)
				break;
			if (symbol_ != obj.symbol_)
				break;
			if (value_ != obj.value_)
				break;
			if (objects_ != objects_)
				break;

			do {
				if (objects_.size() != obj.objects_.size())
					break;
				result = true;
				if (objects_.empty())
					break;
				for (size_t i = 0; i < objects_.size(); ++i) {
					if (objects_.at(i) == obj.objects_.at(i))
						continue;
					result = false;
					break;
				}
			} while (0);

		} while (0);
		return result;
	}
};