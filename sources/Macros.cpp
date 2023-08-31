#include "../headers/Space.h"
#include <tchar.h>
#include <tlhelp32.h>

void RunMacros(mcrs::Space& space) 
{

}

void ReturnDefaultState()
{

}

std::string GetExeFileNameFromPath(std::string const& path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

bool mcrs::LaunchProgram(mcrs::Program& program)
{
	//TODO: in UI add oppoturnity take app from list with installed app
	//and manually add path to the exe file

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
    

    return result;
}

DWORD mcrs::FindProcessId(std::string& exeName)
{
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);


    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (processesSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    Process32First(processesSnapshot, &processInfo);
    if (!exeName.compare(processInfo.szExeFile))
    {
        CloseHandle(processesSnapshot);
        return processInfo.th32ProcessID;
    }


    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (!exeName.compare(processInfo.szExeFile))
        {
            CloseHandle(processesSnapshot);
            return processInfo.th32ProcessID;
        }
    }

    CloseHandle(processesSnapshot);
    return 0;
}


DWORD CloseProcessById(DWORD& processId)
{
    const auto process = OpenProcess(PROCESS_TERMINATE, false, processId);
    if (TerminateProcess(process, 1))
    {
        CloseHandle(process);
        return 1;
    }
    
    CloseHandle(process);
    return -1;
}


DWORD mcrs::CloseProgram(mcrs::Program& program)
{
    std::string exeName = GetExeFileNameFromPath(program.cmd_);
    DWORD processId = mcrs::FindProcessId(exeName);
    if (CloseProcessById(processId)) return 1;

    return -1;
}

void BlockProgram()
{
    
}