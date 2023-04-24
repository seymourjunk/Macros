#pragma once
#include <string>
#include <tuple>
#include <vector>
#include "../headers/nlohmann/json.hpp"

using json = nlohmann::json;

namespace ns {
	enum class ProgramActionType {
		LAUNCH,
		CLOSE,
		BLOCK
	};

	NLOHMANN_JSON_SERIALIZE_ENUM(ProgramActionType, {
	{ProgramActionType::LAUNCH, "launch"},
	{ProgramActionType::CLOSE, "close"},
	{ProgramActionType::BLOCK, "block"},
		})

	struct Program {
		std::string path;
		std::string args;
		std::string cmd;
		ProgramActionType programActionType;
	};

	inline void from_json(const json& j, Program& p)
	{
		j.at("path").get_to(p.path);
		j.at("args").get_to(p.args);
		j.at("cmd").get_to(p.cmd);;
		j.at("programActionType").get_to(p.programActionType);;
	}

	struct Setting {
		std::string name;
		std::string args;
		std::string cmd;
	};

	inline void from_json(const json& j, Setting& s)
	{
		j.at("name").get_to(s.name);
		j.at("args").get_to(s.args);
		j.at("cmd").get_to(s.cmd);;
	}


	class Space {
	public:
		void SetName();
		void AddProgram();
		void AddSetting();

	public:
		std::string name;
		std::vector<Program> programs;
		std::vector<Setting> settings;
	};

	inline void from_json(const json& j, Space& s) 
	{
		j.at("name").get_to(s.name);
		j.at("programs").get_to<std::vector<Program>>(s.programs);
		j.at("settings").get_to<std::vector<Setting>>(s.settings);
	}

}