#pragma once
#include <string>
#include <tuple>
#include <vector>
#include "../headers/nlohmann/json.hpp"
#include <Windows.h>

using json = nlohmann::json;

namespace mcrs {
	struct Program {
		Program() {};

		Program(std::string path, std::string args, std::string cmd, std::string programActionType)
		{
			path_ = path;
			args_ = args;
			cmd_ = cmd;
			programActionType_ = programActionType;
		}

		std::string path_;
		std::string args_;
		std::string cmd_;
		std::string programActionType_;
	};

	inline void from_json(const json& j, Program& p)
	{
		j.at("path").get_to(p.path_);
		j.at("args").get_to(p.args_);
		j.at("cmd").get_to(p.cmd_);;
		j.at("programActionType").get_to(p.programActionType_);;
	}

	struct Setting {
		Setting() {};

		Setting(std::string name, std::string args, std::string cmd)
		{
			name_ = name;
			args_ = args;
			cmd_ = cmd;
		}

		std::string name_;
		std::string args_;
		std::string cmd_;
	};

	inline void from_json(const json& j, Setting& s)
	{
		j.at("name").get_to(s.name_);
		j.at("args").get_to(s.args_);
		j.at("cmd").get_to(s.cmd_);;
	}

	class Space {
	public:
		void SetName(std::string name)
		{
			name_ = name;
		}

		void AddProgram(std::string path, std::string args, std::string cmd, std::string programActionType)
		{
			Program program(path, args, cmd, programActionType);
			programs_.push_back(program);
		}

		void RemoveProgram()
		{

		}

		void AddSetting(std::string name, std::string args, std::string cmd)
		{
			Setting setting(name, args, cmd);
			settings_.push_back(setting);
		}

		void RemoveSetting() {

		}

	public:
		std::string name_;
		std::vector<Program> programs_;
		std::vector<Setting> settings_;
	};

	inline void from_json(const json& j, Space& s) 
	{
		j.at("name").get_to(s.name_);
		j.at("programs").get_to<std::vector<Program>>(s.programs_);
		j.at("settings").get_to<std::vector<Setting>>(s.settings_);
	}


	bool LaunchProgram(Program& program);
	DWORD FindProcessId(std::string& exeName);
	DWORD CloseProgram(Program& program);
	void BlockProgram();
}