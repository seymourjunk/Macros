// Macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "Configuration.cpp"
#include "../headers/Space.h"


std::string ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}


int main()
{
    std::string exePath = ExePath();
    std::string configPath = exePath + "\\config.json";
    mcrs::Space space;
    

    Configuration config(configPath);
    if (config.json_ != NULL) {
        space = config.DeserializationJSONToObject();
    }
    else {
        //create empty config
    }
    
    printf(
        "Press C to create space"
    );

    //printf(
    //    "-c     create space"
    //    "-r     delete space"
    //    "-n     rename space"
    //    "-l     list of spaces"
    //);
}
