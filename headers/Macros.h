#pragma once
#include <string>
#include <vector>


enum class ProgramActionType {
	LAUNCH,
	CLOSE,
	BLOCK
};

struct Program {
	std::wstring path;
	std::wstring args;
	std::wstring cmd;
	ProgramActionType programActionType;
};

struct Setting {
	std::wstring name;
	std::wstring args;
	std::wstring cmd;
};

struct Space {
	std::wstring name;
	std::vector<Program> programs;
	std::vector<Setting> settings;
};

//struct Macros {
//	MacrosType macrosType;
//	union {
//		Program program;
//		Configuration configuration;
//	};
//};

enum class MacrosType {
	MACROS_PROGRAM,
	MACROS_CONFIGURATION
};



