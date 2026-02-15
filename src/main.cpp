#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

#include "../includes/Menu.h"
#include "../includes/GetUserInput.h"
#include "../includes/ClearTerminal.h"
#include "../includes/Benchmark.h"
#include "../includes/PrintAndSaveResult.h"
#include "../includes/LoadingBar.h"

int main()
{
    std::vector<std::thread> threads;
    std::atomic<bool> isWorking{true};
    Benchmark benchmark;

    bool repeatMenu = true;
    while (repeatMenu)
    {
        clearTerminal();
        printMenu();
        std::cout << ">> ";
        const auto userInput = getUserInput();
        double duration{};

        switch (userInput)
        {
            case '1':
                threads.emplace_back(
                    &Benchmark::startBenchmark,
                    &benchmark,
                    std::thread::hardware_concurrency(),
                    std::ref(isWorking)
                );
                repeatMenu = false;
                break;

            case '2':
                threads.emplace_back(
                    &Benchmark::startBenchmark,
                    &benchmark,
                    1,
                    std::ref(isWorking)
                );
                repeatMenu = false;
                break;
            case '3':
                return 0;
        }


        startLoadingBar(isWorking);

        for (auto& thread : threads)
            thread.join();

        printResult(benchmark.duration);
    }
}
