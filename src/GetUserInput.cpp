//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <string>

#include "GetUserInput.h"

char GetUserInput::getUserInput()
{
    // Clear errors
    error.clear();

    std::string userInput;
    std::cin >> userInput;

    if (userInput.length() > 1)
    {
        error = " - Enter one character - ";
        return '0';
    }

    return userInput[0];
}

const std::string& GetUserInput::getError() const
{
    return error;
}

void GetUserInput::setError(const std::string &error_)
{
    error = error_;
}
