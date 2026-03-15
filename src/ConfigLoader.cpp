//
// Created by bartek on 2/24/26.
//

#include "../includes/ConfigLoader.h"

std::unordered_map<std::string, std::string>
ConfigLoader::load(const std::string& pathAndFileName)
{
    std::unordered_map<std::string,std::string> config;

    std::fstream file(pathAndFileName, std::ios::in);
    checkFile(file);

    std::string line;
    while (std::getline(file, line))
    {
        // Check if line is comment, if is then skip
        // # comment
        if (!line.empty() && line.at(0) == '#')
            continue;

        // Delete test after '#'
        // value = key # comment
        size_t commentPos = line.find('#');
        if (commentPos != std::string::npos)
            line.erase(commentPos, line.length());

        size_t pos = line.find('=');
        if (pos == std::string::npos)
            continue;

        std::string key  = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        deleteSpaces(value);
        deleteSpaces(key);

        config[key] = value;
    }
    return config;
}

void ConfigLoader::checkFile(const std::fstream& file)
{
    if (!file.is_open())
        throw std::runtime_error("Config not found, missing config/config.txt");

    if (file.fail())
        throw std::runtime_error("Error file failed");
}

void ConfigLoader::deleteSpaces(std::string& line)
{
    if (line.empty())
        return;

    const size_t start = line.find_first_not_of(' ');

    if (start == std::string::npos)
    {
        line.clear();
        return;
    }

    // Delete from left site
    line.erase(0,start);

    const size_t end = line.find_last_not_of(' ');

    // Delete from right site
    line.erase(end + 1);
}