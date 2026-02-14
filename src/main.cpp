#include <iostream>
#include <thread>

#include "../includes/Menu.h"
#include "../includes/GetUserInput.h"
#include "../includes/ClearTerminal.h"
#include "../includes/Benchmark.h"

int main()
{
    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();
        std::cout << ">> ";
        const auto userInput = getUserInput();
        Benchmark b1;
        double duration{};

        switch (userInput)
        {
            case '1':
                duration = b1.startBenchmark(std::thread::hardware_concurrency());
                repeatMenu = false;
                break;

            case '2':
                duration = b1.startBenchmark(1);
                repeatMenu = false;
                break;

            case '3':
                return 0;
        }
        std::cout << duration << "s" << std::endl;
    }
}