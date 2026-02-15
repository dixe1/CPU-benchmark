//
// Created by bartek on 2/15/26.
//

#pragma once
#include <atomic>
#include <array>
#include <string>
#include <thread>
#include <chrono>
#include "../includes/ClearTerminal.h"

inline void startLoadingBar(const std::atomic<bool>& isWorking)
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