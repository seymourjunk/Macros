// Macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "Configuration.cpp"


std::wstring ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}


int main()
{
    std::wstring exePath = ExePath();
    std::wstring configPath = exePath + L"\\config.json";


    Configuration config(configPath);
    //Space space
    
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
