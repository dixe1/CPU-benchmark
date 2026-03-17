//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include "PrintAndSaveResult.h"
#include "GetCPUName.h"

void printAndSaveResult(const Application& app)
{
    std::ofstream resultFile("Result.log");

    if (!resultFile.is_open())
        throw std::runtime_error("resultFile can't be open");

    if (resultFile.fail())
        throw std::runtime_error("resultFile failed");

    auto print = [&](std::ostream& out)
    {
        out << "BENCHMARK REPORT\n";
        out << "────────────────────────────────\n\n";
        out << "CPU      : " << getCPUName() << "\n\n";
        out << "cycles   : " << app.getConfig().at("cycles") << "\n";
        out << "num      : " << app.getConfig().at("num") << "\n\n";
        out << "duration : " << app.getBenchmarkDuration() << " seconds\n";
        out << "score    : " << app.getBenchmarkPoints() << " points\n";
    };

    print(resultFile);
    print(std::cout);
}