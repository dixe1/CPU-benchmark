//
// Created by bartek on 2/24/26.
//
#include "ClearTerminal.h"
#include <iostream>

void clearTerminal()
{
    std::cout << "\033[2J\033[H";
}