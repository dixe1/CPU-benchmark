#include <iostream>
#include <thread>
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

    // Set app
    Application app;

    // Set userInput
    GetUserInput userInput;

    if(app.loadConfig("config/config.txt") != 0)
        return 0;

    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();

        // Print errors to the user in gray color
        for (auto& i : userInput.errors)
            std::cout << "\033[90m" << i << "\033[0m\n";

        // If there is no error print new line to make space
        if (userInput.errors.empty())
            std::cout << '\n';

        std::cout << ">> "; // This is that think before cursor

        // Thread for starting benchmark
        std::thread startThread;

        switch (userInput.getUserInput())
        {
            case '1':   // Multi core
                startThread = std::thread(&Application::startMultiCore, &app);
                break;

            case '2':   // Single core
                startThread = std::thread(&Application::startSingleCore, &app);
                break;

            case '3':   // Stress test
                startThread = std::thread(&Application::startStressTest, &app);
                break;
            case '4':
                return 0;
            default:
                clearTerminal();
                continue;
        }
        repeatMenu = false;

        startLoadingBar(app.isBenchmarkRunning);

        if (startThread.joinable())
            startThread.join();

        try
        {
            printAndSaveResult(app);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
