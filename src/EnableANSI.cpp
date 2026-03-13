//
// Created by bartek on 3/13/26.
//

#include "../includes/EnableANSI.h"

// Enable ANSI only if is on Windows
// linux default works

#ifdef _WIN32
    #include <windows.h>
#endif

void enableANSI()
{
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    #endif
}
