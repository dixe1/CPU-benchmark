//
// Created by bartek on 2/24/26.
//

#include <print>
#include <string>
#include "Menu.h"

namespace
{
    // Colors
    constexpr auto GREEN   = "\033[32m";
    constexpr auto CYAN    = "\033[36m";
    constexpr auto YELLOW  = "\033[33m";

    // Other
    constexpr auto RESET   = "\033[0m";
    constexpr auto DIM     = "\033[2m";
    constexpr auto BOLD    = "\033[1m";

    void option(char key,const std::string& name)
    {
        std::println("[{}{}{}] {}", CYAN,key,RESET, name);
    }
    void header(const std::string& version)
    {
        std::println(" {}─────────── {} ───────────{}", GREEN,version,RESET);
    }
    void section(const std::string& str)
    {
        std::print("\n{}{} {} {}\n", DIM, CYAN, str, RESET);
    }
}

void printMenu()
{
    header("v1.1.0");

    section("Benchmark");
    option('1', "Multi core");
    option('2', "Single core");

    section("Stress test");
    option('3', "Multi core");
    option('4', "Single core");

    section("──────");
    option('5', "Exit");
}