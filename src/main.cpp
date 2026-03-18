#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "Menu.h"
#include "GetUserInput.h"
#include "ClearTerminal.h"
#include "PrintAndSaveResult.h"
#include "LoadingBar.h"
#include "Application.h"
#include "EnableANSI.h"

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


        // Print errors to the user, if there is no errors print new line
        if (userInput.getError().empty())
            std::cout << '\n';
        else
            std::cout << "\033[90m" << userInput.getError() << "\033[0m\n";    // gray color

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
                if (userInput.getError().empty())
                    userInput.setError(" - Invalid option - ");
                continue;
        }
        repeatMenu = false;

        startLoadingBar(app);

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

    // Dont close window
    std::cin.ignore();
    std::cin.get();
}
