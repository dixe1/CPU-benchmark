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

int main()
{
    Application app;
    app.loadConfig("config/config.txt");

    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();
        std::cout << ">> ";
        const auto userInput = getUserInput();

        std::vector<std::thread> thread;

        switch (userInput)
        {
            case '1':   // Multi core
                repeatMenu = false;
                thread.emplace_back(&Application::startMultiCore, &app);
                break;

            case '2':   // Single core
                repeatMenu = false;
                thread.emplace_back(&Application::startSingleCore, &app);
                break;

            case '3':   // Stress test
                repeatMenu = false;
                thread.emplace_back(&Application::startStressTest, &app);
                break;
            case '4':
                return 0;
        }

        startLoadingBar(app.isWorking);
        thread.at(0).join();
        printResult(app.benchmarkDuration);
    }
}
