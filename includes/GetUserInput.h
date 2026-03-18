//
// Created by bartek on 2/14/26.
//

#pragma once
#include <string>

class GetUserInput
{
    private:
    // std::vector<std::string> errors;
    std::string errors;

    public:
    char getUserInput();
    [[nodiscard]] const std::string& getErrors() const;
};