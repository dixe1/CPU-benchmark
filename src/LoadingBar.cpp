//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <atomic>
#include <array>
#include <string>
#include <thread>
#include <chrono>

#include "../includes/LoadingBar.h"
#include "../includes/ClearTerminal.h"

void startLoadingBar(const std::atomic<bool>& isWorking)
{
    const std::array<std::string, 6> loading {".","..","...", "....", ".....", "......"};
    int i{};
    while (isWorking)
    {
        if (i > 5) i = 0;
        std::cout << loading.at(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        clearTerminal();
        i++;
    }
}
