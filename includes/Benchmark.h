//
// Created by bartek on 2/14/26.
//
#pragma once

#include "../includes/ConfigLoader.h"

class Benchmark
{
private:
    const std::unordered_map<std::string, std::string> config = ConfigLoader::load("config/config.txt");
    double calculate(size_t threads, bool stressTest) const;

public:
    double duration{};

    void startBenchmark(size_t threadsToUse, std::atomic<bool>& isWorking, bool stressTest);
};
