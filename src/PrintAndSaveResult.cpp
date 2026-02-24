//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <unordered_map>
#include <fstream>

#include "../includes/PrintAndSaveResult.h"
#include "../includes/ConfigLoader.h"

void printResult(const double duration)
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