#pragma once
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

enum class ActionType : Key {
	UNKNOWN = 0,
	IF = 1,
	ELIF = 2,
	ELSE = 3,
	ENDIF = 4,
	DEFINE = 5,
};
enum class ObjectType : Key {
	UNKNOWN = 0,
	BOOLEAN = 1,
	FLOAT = 2,//!@ 浮点型对象
	DATA = 3, //!@ 数据对象 json(object)
	OPERATOR = 4,//!@ 运算符对象
	STRING = 5,//!@ 字符串对象
	INTEGER = 6,//!@ 整型对象(有符号)
	CONDITION = 7,//!@ 条件对象
};




