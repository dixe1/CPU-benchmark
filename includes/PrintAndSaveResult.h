//
// Created by bartek on 2/15/26.
//

#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include "../includes/ConfigLoader.h"

inline void printResult(const double duration)
{
    const auto config = ConfigLoader::load("config/config.txt");
    std::ofstream resultFile("Result.log");

    // Not pretty but works

    resultFile << "------- DATA --------\n";
    resultFile << "cycles: " << config.at("cycles") << "\n";
    resultFile << "num: " << config.at("num") << "\n";
    resultFile << "result [less - better]: " << duration << "s\n";

    std::cout << "------- DATA --------\n";
    std::cout << "cycles: " << config.at("cycles") << "\n";
    std::cout << "num: " << config.at("num") << "\n";
    std::cout << "result [less - better]: " << duration << "s\n";
}