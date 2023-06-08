#include "../headers/Space.h"
#include <tchar.h>
#include <Windows.h>


void RunMacros(mcrs::Space& space) 
{

}

void ReturnDefaultState()
{

}

bool mcrs::LaunchProgram(mcrs::Program& program)
{
	//TODO: in UI add oppoturnity take app from list with installed app
	//and manually add path to the exe file

    LPSTR s = const_cast<char*>(program.cmd_.c_str());


    //TODO: add opportunity to add argument to run exe (program.args_)
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi;

    // Start the child process. 
    bool result = CreateProcess(NULL,   // No module name (use command line) _strdup(program.cmd_.c_str())
        LPTSTR(program.cmd_.c_str()),        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi);           // Pointer to PROCESS_INFORMATION structure
 
    if (!result) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return result;
    }
    /*CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);*/

    return result;
}

void CloseProgram()
{

}

void BlockProgram()
{

}
