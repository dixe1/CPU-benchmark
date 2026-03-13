#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

#include "../includes/Menu.h"
#include "../includes/GetUserInput.h"
#include "../includes/ClearTerminal.h"
#include "../includes/PrintAndSaveResult.h"
#include "../includes/LoadingBar.h"
#include "../includes/Application.h"
#include "../includes/EnableANSI.h"

int main()
{
    // Enable ANSI in console if is on Windows
    #ifdef _WIN32
        enableANSI();
    #endif

    Application app;
    if(app.loadConfig("config/config.txt") != 0)
        return 0;

    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();
        std::cout << ">> ";
        const auto userInput = getUserInput();

        std::vector<std::thread> threads;

        switch (userInput)
        {
            case '1':   // Multi core
                repeatMenu = false;
                threads.emplace_back(&Application::startMultiCore, &app);
                break;

            case '2':   // Single core
                repeatMenu = false;
                threads.emplace_back(&Application::startSingleCore, &app);
                break;

            case '3':   // Stress test
                repeatMenu = false;
                threads.emplace_back(&Application::startStressTest, &app);
                break;
            case '4':
                return 0;
            default:
                clearTerminal();
                continue;
        }

        startLoadingBar(app.isBenchmarkRunning);
        threads.at(0).join();
        printAndSaveResult(app);
    }
}
