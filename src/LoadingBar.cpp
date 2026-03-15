//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <atomic>
#include <array>
#include <string>
#include <thread>
#include <chrono>

#include "../includes/Application.h"
#include "../includes/LoadingBar.h"
#include "../includes/ClearTerminal.h"

void startLoadingBar(const Application& app)
{
    constexpr std::array<std::string_view, 6> loading {".","..","...", "....", ".....", "......"};
    int i{};
    while (app.getIsBenchmarkRunning())
    {
        if (i > 5) i = 0;
        std::cout << loading.at(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        clearTerminal();
        i++;
    }
}
