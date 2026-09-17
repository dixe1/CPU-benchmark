#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "Application.h"
#include "ClearTerminal.h"
#include "EnableANSI.h"
#include "GetUserInput.h"
#include "LoadingBar.h"
#include "Menu.h"
#include "PrintAndSaveResult.h"

namespace
{
enum class RunMode
{
    BENCHMARK_MULTI = '1',
    BENCHMARK_SINGLE = '2',
    STRESS_MULTI = '3',
    STRESS_SINGLE = '4',
    INVALID = '5'
};

RunMode handleArguments(char* argv[])
{
    const std::string typeArg = argv[1];
    const std::string coresArg = argv[2];

    if (typeArg == "--benchmark" && coresArg == "--multi-core")
        return RunMode::BENCHMARK_MULTI;
    if (typeArg == "--benchmark" && coresArg == "--single-core")
        return RunMode::BENCHMARK_SINGLE;
    if (typeArg == "--stress-test" && coresArg == "--multi-core")
        return RunMode::STRESS_MULTI;
    if (typeArg == "--stress-test" && coresArg == "--single-core")
        return RunMode::STRESS_SINGLE;

    return RunMode::INVALID;
}
} // namespace

int main(int argc, char* argv[])
{
// Enable ANSI in console if is on Windows
#ifdef _WIN32
    enableANSI();
#endif

    // Set app
    Application app;

    RunMode runMode = RunMode::INVALID;
    const bool argumentsEntered = (argc > 1 && argc < 4);
    if (argumentsEntered)
        runMode = handleArguments(argv);

    // Set userInput
    GetUserInput userInput;

    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();

        // Print errors to the user, if there is no errors print new line
        if (userInput.getError().empty())
            std::cout << '\n';
        else
            std::cout << "\033[90m" << userInput.getError()
                      << "\033[0m\n"; // gray color

        std::cout << ">> "; // This is that think before cursor

        // Thread for starting benchmark
        std::thread startThread;

        // If arguments were entered use them
        char userChoice;
        if (argumentsEntered)
            userChoice = static_cast<char>(runMode);
        else
            userChoice = userInput.getUserInput();

        switch (userChoice)
        {
        case '1':
            startThread = std::thread(&Application::benchmarkMultiCore, &app);
            break;

        case '2':
            startThread = std::thread(&Application::benchmarkSingleCore, &app);
            break;

        case '3':
            startThread = std::thread(&Application::stressTestMultiCore, &app);
            break;

        case '4':
            startThread = std::thread(&Application::stressTestSingleCore, &app);
            break;

        case '5':
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
