//
// Created by bartek on 2/13/26.
//

#pragma once
#include <fstream>
#include <string>
#include <unordered_map>


class ConfigLoader
{
public:

    static std::unordered_map<std::string, std::string>
    load(const std::string& pathAndFileName);

private:

    // Helper functions
    static void checkFile(const std::fstream& file);
    static void deleteSpaces(std::string& line);
};