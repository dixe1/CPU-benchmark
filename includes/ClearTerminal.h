//
// Created by bartek on 2/14/26.
//

#pragma once
#include <iostream>

inline void clearTerminal()
{
    std::cout << "\033[2J\033[H";
}
