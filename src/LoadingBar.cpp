//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <array>
#include <string>
#include <thread>
#include <chrono>

#include "Application.h"
#include "LoadingBar.h"
#include "ClearTerminal.h"

void startLoadingBar(const Application& app)
{
    constexpr std::array<std::string_view, 6> loading {".","..","...", "....", ".....", "......"};
    int i{};
    while (app.getIsBenchmarkRunning())
    {
        if (i > 5) i = 0;
        std::cout << loading.at(i++) << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        clearTerminal();
    }
}
