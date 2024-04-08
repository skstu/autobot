#pragma once
using Key = int;

class Types {//!@ ����
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
	FLOAT = 2,//!@ �����Ͷ���
	DATA = 3, //!@ ���ݶ��� json(object)
	OPERATOR = 4,//!@ ���������
	STRING = 5,//!@ �ַ�������
	INTEGER = 6,//!@ ���Ͷ���(�з���)
	CONDITION = 7,//!@ ��������
};




