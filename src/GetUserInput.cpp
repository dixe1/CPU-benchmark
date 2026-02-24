//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <string>

#include "../includes/GetUserInput.h"

char getUserInput()
{
    std::string userInput;
    std::cin >> userInput;

    if (userInput.empty())
        userInput = "0";

    return userInput[0];
}
