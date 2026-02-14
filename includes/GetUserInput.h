//
// Created by bartek on 2/14/26.
//

#pragma once
#include <iostream>
#include <string>

inline char getUserInput()
{
    std::string userInput;
    std::cin >> userInput;

    if (userInput.empty())
        userInput = "0";

    return userInput[0];
}