//
// Created by bartek on 2/24/26.
//

#include "PrintAndSaveResult.h"
#include "Config.h"
#include "GetCPUName.h"
#include <format>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using nlohmann::json;

namespace
{
void saveJSON(const Application& app, std::ofstream& resultFile)
{
    json result;
    result["cpu"] = getCPUName();
    result["cycles"] = Config::cycles;
    result["num"] = Config::num;
    result["duration"] = app.getBenchmarkDuration();
    result["score"] = app.getBenchmarkPoints();
    resultFile << result;
}

struct Colors
{
    // Colors
    const std::string GREEN = "\033[32m";
    const std::string CYAN = "\033[36m";
    const std::string YELLOW = "\033[33m";

    // Other
    const std::string RESET = "\033[0m";
    const std::string DIM = "\033[2m";
    const std::string BOLD = "\033[1m";

    static Colors ON() { return {}; }
    static Colors OFF()
    {
        return {.GREEN = "",
                .CYAN = "",
                .YELLOW = "",
                .RESET = "",
                .DIM = "",
                .BOLD = ""};
    }
};
} // namespace

void printAndSaveResult(const Application& app)
{
    auto output = [&](std::ostream& out, const Colors& c)
    {
        out << std::format("{}{}BENCHMARK REPORT{}\n", c.BOLD, c.GREEN,
                           c.RESET);
        out << std::format("{}──────────────────────────────────────────{}\n",
                           c.DIM, c.RESET);
        out << std::format("{}{}CPU{}: {}\n", c.BOLD, c.YELLOW, c.RESET,
                           getCPUName());
        out << std::format("{}{}cycles{}: {}\n", c.BOLD, c.YELLOW, c.RESET,
                           Config::cycles);
        out << std::format("{}{}num{}: {}\n\n", c.BOLD, c.YELLOW, c.RESET,
                           Config::num);
        out << std::format("{}{}duration{}: {} seconds\n", c.BOLD, c.YELLOW,
                           c.RESET, app.getBenchmarkDuration());
        out << std::format("{}{}score{}: {} points\n", c.BOLD, c.YELLOW,
                           c.RESET, app.getBenchmarkPoints());
    };

    // Print result to console
    output(std::cout, Colors::ON());

    // Save result to nice formated file
    {
        std::ofstream result("result.log");
        if (!result)
            throw std::runtime_error("'result.log' failed");

        output(result, Colors::OFF());
    }

    // Save result to JSON file
    std::ofstream result("result.json");
    if (!result)
        throw std::runtime_error("'result.json' failed");
    saveJSON(app, result);
}