//
// Created by bartek on 2/24/26.
//
#include <iostream>

#include "../includes/ClearTerminal.h"

void clearTerminal()
{
    std::cout << "\033[2J\033[H";
}