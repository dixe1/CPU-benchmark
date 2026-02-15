#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <array>
#include <chrono>
#include "unordered_map"

#include "../includes/Menu.h"
#include "../includes/GetUserInput.h"
#include "../includes/ClearTerminal.h"
#include "../includes/Benchmark.h"
#include "../includes/ConfigLoader.h"

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

        std::array<std::string, 6> loading {".","..","...", "....", ".....", "......"};
        int i{};
        while (isWorking)
        {
            if (i > 5) i = 0;
            std::cout << loading.at(i) << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            clearTerminal();
            i++;
        }

        threads[0].join();
        auto config = ConfigLoader::load("config/config.txt");

        std::cout << "======= DATA =======\n";
        std::cout << "cycles: " << config.at("cycles") << "\n";
        std::cout << "num: " << config.at("num") << "\n";
        std::cout << "duration [less - better]: " << benchmark.duration << "s\n";
    }
}