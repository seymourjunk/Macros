#include <fstream>
#include <Windows.h>
#include "../headers/nlohmann/json.hpp"
#include "../headers/Macros.h"

using json = nlohmann::json;


class Configuration {
public:
	Configuration(std::wstring path) {
		path_ = path;
		if ((0xffffffff == GetFileAttributes(path_.c_str())) && IsError())
		{
			printf("The config not found. A new config would be created.");
			CreateEmptyConfig();
			SerializationToFile();
		}
		else {
			ParseConfig();
			//DeserializationJSONToObject();
		}
	}

private:
	void ParseConfig() {
		std::ifstream f(path_);
		json_ = json::parse(f);
	}

	void CreateEmptyConfig() {
		json_ = json::parse(R"(
		  {
		    "user": "user",
		    "spaces": []
		  }
		)");
	}

	void SerializationToFile(){
		std::ofstream o(path_);
		o << std::setw(4) << json_ << std::endl;
		o.close();
	}

	//Space DeserializationJSONToObject() {
	//	//space_
	//}

	int IsError()
	{
		if ((GetLastError() == ERROR_FILE_NOT_FOUND) || (GetLastError() == ERROR_PATH_NOT_FOUND) ||
			(GetLastError() == ERROR_INVALID_NAME) || (GetLastError() == ERROR_INVALID_DRIVE) ||
			(GetLastError() == ERROR_NOT_READY) || (GetLastError() == ERROR_INVALID_PARAMETER) ||
			(GetLastError() == ERROR_BAD_PATHNAME) || (GetLastError() == ERROR_BAD_NETPATH))
		{
			return 1;
		}
		//TODO: add log

		return 0;
	}


public:
	std::wstring path_;
	json json_;
	Space space_;

};