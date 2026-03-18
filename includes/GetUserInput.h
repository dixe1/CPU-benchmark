//
// Created by bartek on 2/14/26.
//

#pragma once
#include <string>

class GetUserInput
{
    private:
    std::string error;

    public:
    char getUserInput();
    [[nodiscard]] const std::string& getError() const;
    void setError(const std::string& error_);
};