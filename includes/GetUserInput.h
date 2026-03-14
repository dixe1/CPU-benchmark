//
// Created by bartek on 2/14/26.
//

#pragma once
#include <vector>

class GetUserInput
{
    private:
    std::vector<std::string> errors;

    public:
    char getUserInput();
    const std::vector<std::string>& getErrors() const;
};