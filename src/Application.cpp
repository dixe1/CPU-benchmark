//
// Created by bartek on 2/27/26.
//
#include <thread>
#include <cmath>

#include "../includes/Application.h"

#include <iostream>

#include "../includes/ConfigLoader.h"
#include "../includes/Benchmark.h"

int Application::loadConfig(const std::string &fileName)
{
    try
    {
        config = ConfigLoader::load(fileName);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}

void Application::startMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), false, config);
    isBenchmarkRunning = false;

    calculatePoints();
}
void Application::startSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, false, config);
    isBenchmarkRunning = false;

    calculatePoints();
}

void Application::startStressTest()
{
    isBenchmarkRunning = true;
    const auto threadsToUse = std::thread::hardware_concurrency();
    benchmarkDuration = Benchmark::startBenchmark(threadsToUse, true, config);
    isBenchmarkRunning = false;

    calculatePoints();
}


void Application::calculatePoints()
{
    const uint64_t cycles = std::stoull(config.at("cycles"));
    const double points = static_cast<double>(cycles) / benchmarkDuration * 1e-6;
    benchmarkPoints = static_cast<int>(std::round(points));
}
