//
// Created by bartek on 2/24/26.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <format>
#include "PrintAndSaveResult.h"
#include "GetCPUName.h"

namespace
{
    // Colors
    std::string GREEN   = "\033[32m";
    std::string CYAN    = "\033[36m";
    std::string YELLOW  = "\033[33m";

    // Other
    std::string RESET   = "\033[0m";
    std::string DIM     = "\033[2m";
    std::string BOLD    = "\033[1m";

    void colorsOFF()
    {
        GREEN   .clear();
        CYAN    .clear();
        YELLOW  .clear();
        RESET   .clear();
        DIM     .clear();
        BOLD    .clear();
    }
    void colorsON()
    {
        GREEN   = "\033[32m";
        CYAN    = "\033[36m";
        YELLOW  = "\033[33m";
        RESET   = "\033[0m";
        DIM     = "\033[2m";
        BOLD    = "\033[1m";
    }

    std::string header()
    {
        return std::format("{}{}BENCHMARK REPORT{}\n",BOLD, GREEN, RESET);
    }
    std::string separator()
    {
        return std::format("{}──────────────────────────────────────────{}\n", DIM, RESET);
    }
    std::string CPU(const std::string& CPUName)
    {
        return std::format("{}{}CPU{}: {}\n", BOLD, YELLOW, RESET, CPUName);
    }
    std::string cycles(const std::string& cycles)
    {
        return std::format("{}{}cycles{}: {}\n", BOLD, YELLOW, RESET, cycles);
    }
    std::string num(const std::string& num)
    {
        return std::format("{}{}num{}: {}\n\n", BOLD, YELLOW, RESET, num);
    }
    std::string duration(double duration)
    {
        return std::format("{}{}duration{}: {} seconds\n", BOLD, YELLOW, RESET, duration);
    }
    std::string score(int score)
    {
        return std::format("{}{}score{}: {} points\n", BOLD, YELLOW, RESET, score);
    }
}


void printAndSaveResult(const Application& app)
{
    auto print = [&](std::ostream& out)
    {
        out << header();
        out << separator();
        out << CPU(getCPUName());
        out << cycles(app.getConfig().at("cycles"));
        out << num(app.getConfig().at("num"));
        out << duration(app.getBenchmarkDuration());
        out << score(app.getBenchmarkPoints());
    };

    // Print to console
    print(std::cout);

    // Save to file
    std::ofstream resultFile("Result.log");
    if (!resultFile.is_open())
        throw std::runtime_error("resultFile can't be open");

    if (resultFile.fail())
        throw std::runtime_error("resultFile failed");

    colorsOFF();
    print(resultFile);
    colorsON(); // not necessary
}