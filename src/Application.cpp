//
// Created by bartek on 2/27/26.
//
#include <thread>

#include "../includes/Application.h"
#include "../includes/ConfigLoader.h"
#include "../includes/Benchmark.h"

void Application::loadConfig(const std::string &fileName)
{
    config = ConfigLoader::load(fileName);
}

void Application::startMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), false, config);
    isBenchmarkRunning = false;
}
void Application::startSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, false, config);
    isBenchmarkRunning = false;

}

void Application::startStressTest()
{
    isBenchmarkRunning = true;
    const auto threadsToUse = std::thread::hardware_concurrency();
    benchmarkDuration = Benchmark::startBenchmark(threadsToUse, true, config);
    isBenchmarkRunning = false;
}


