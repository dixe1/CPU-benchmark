//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <format>
#include <vector>
#include "PrintAndSaveResult.h"
#include "GetCPUName.h"

namespace
{
    struct Colors
    {
        // Colors
        const std::string GREEN   = "\033[32m";
        const std::string CYAN    = "\033[36m";
        const std::string YELLOW  = "\033[33m";

        // Other
        const std::string RESET   = "\033[0m";
        const std::string DIM     = "\033[2m";
        const std::string BOLD    = "\033[1m";

        static Colors ON()
        {
            return {};
        }
        static Colors OFF()
        {
            return {"","","","","",""};
        }
    };
}


void printAndSaveResult(const Application& app)
{
    auto output = [&](std::ostream& out,const Colors& c)
    {
        auto header = [&]()
        {
            return std::format("{}{}BENCHMARK REPORT{}\n",c.BOLD, c.GREEN, c.RESET);
        };
        auto separator = [&]()
        {
            return std::format("{}──────────────────────────────────────────{}\n", c.DIM, c.RESET);
        };
        auto CPU = [&]()
        {
            return std::format("{}{}CPU{}: {}\n", c.BOLD, c.YELLOW, c.RESET, getCPUName());
        };
        auto cycles = [&]()
        {
            return std::format("{}{}cycles{}: {}\n", c.BOLD, c.YELLOW, c.RESET, std::any_cast<long long>(app.getConfig().at("cycles")));
        };
        auto num = [&]()
        {
            return std::format("{}{}num{}: {}\n\n", c.BOLD, c.YELLOW, c.RESET, std::any_cast<double>(app.getConfig().at("num")));
        };
        auto duration = [&]()
        {
            return std::format("{}{}duration{}: {} seconds\n", c.BOLD, c.YELLOW, c.RESET, app.getBenchmarkDuration());
        };
        auto score = [&]()
        {
            return std::format("{}{}score{}: {} points\n", c.BOLD, c.YELLOW, c.RESET, app.getBenchmarkPoints());
        };

        out << header();
        out << separator();
        out << CPU();
        out << cycles();
        out << num();
        out << duration();
        out << score();
    };

    // Print to console
    output(std::cout, Colors::ON());


    std::ofstream resultFile("Result.log");
    if (!resultFile)
        throw std::runtime_error("resultFile failed");

    // Save to file
    output(resultFile, Colors::OFF());
}