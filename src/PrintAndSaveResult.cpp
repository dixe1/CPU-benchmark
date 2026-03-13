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

    if (!resultFile.is_open())
        throw std::runtime_error("resultFile can't be open");

    if (resultFile.fail())
        throw std::runtime_error("resultFile failed");

    auto print = [&](std::ostream& out)
    {
        out << "------- DATA --------\n";
        out << "cycles: " << app.config.at("cycles") << "\n";
        out << "num: " << app.config.at("num") << "\n";
        out << "result: " << app.benchmarkPoints << " points\n";
    };

    print(resultFile);
    print(std::cout);
}