#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../headers/Space.h"
#include "../headers/nlohmann/json.hpp"

using json = nlohmann::json;

class Configuration {
public:
	Configuration(std::wstring path) {
		path_ = path;
		if (!(0xffffffff == GetFileAttributes(path_.c_str())) && !IsError())
		{
			ParseConfig();
			DeserializationJSONToObject();
		}
	}


private:
	void ParseConfig() {
		std::ifstream f(path_);
		json_ = json::parse(f);
		f.close();
	}

	void CreateEmptyConfig() {
		json_ = json::parse(R"(
		  {
  "name": "work",
  "programs": [
    {
      "cmd": "path1",
      "args": "arguments",
      "path": "path2",
      "programActionType": "block"
    },
    {
      "cmd": "path3",
      "args": "arguments2",
      "path": "path4",
      "programActionType": "launch"
    }
  ],
  "settings": [
    {
      "name": "name",
      "args": "arguments",
      "cmd": "path2"
    }
  ]
}
		)");
	}

	//void SerializationToFile(){
	//	std::ofstream o(path_);
	//	o << std::setw(4) << json_ << std::endl;
	//	o.close();
	//}

	void DeserializationJSONToObject() {
		space_ = json_;
	}

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
	ns::Space space_;
};