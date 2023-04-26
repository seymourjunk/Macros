#include "../headers/Space.h"
#include <tchar.h>
#include <Windows.h>


void RunMacros(mcrs::Space& space) 
{

}

void ReturnDefaultState()
{

}

void LaunchProgram(mcrs::Program& program)
{
	//TODO: in UI add oppoturnity take app from list with installed app
	//and manually add path to the exe file

    //TODO: add opportunity to add argument to run exe (program.args_)
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
    
        
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si); //The size of the structure, in bytes.
	ZeroMemory(&pi, sizeof(pi));

    // Start the child process. 
    if (!CreateProcess(NULL,   // No module name (use command line)
        _strdup(program.cmd_.c_str()),        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }
}

void CloseProgram()
{

}

void BlockProgram()
{

}
