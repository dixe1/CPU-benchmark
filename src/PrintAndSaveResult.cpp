//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include "../includes/PrintAndSaveResult.h"

void printAndSaveResult(const Application& app)
{
    std::ofstream resultFile("Result.log");

    // Not pretty but works

    resultFile << "------- DATA --------\n";
    resultFile << "cycles: " << app.config.at("cycles") << "\n";
    resultFile << "num: " << app.config.at("num") << "\n";
    resultFile << "result [less - better]: " << app.benchmarkDuration << "s\n";

    std::cout << "------- DATA --------\n";
    std::cout << "cycles: " << app.config.at("cycles") << "\n";
    std::cout << "num: " << app.config.at("num") << "\n";
    std::cout << "result [less - better]: " << app.benchmarkDuration << "s\n";
}