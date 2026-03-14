//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <string>

#include "../includes/GetUserInput.h"

char GetUserInput::getUserInput()
{
    // Clear errors
    errors.clear();

    std::string userInput;
    std::cin >> userInput;

    if (userInput.length() > 1)
    {
        errors.emplace_back(" - Enter one character - ");
        return '0';
    }

    return userInput[0];
}

const std::vector<std::string>& GetUserInput::getErrors() const
{
    return errors;
}
