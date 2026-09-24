//
// Created by bartek on 2/24/26.
//
#include "ClearTerminal.h"
#include <print>

void clearTerminal()
{
    std::print("\033[2J\033[H");
}