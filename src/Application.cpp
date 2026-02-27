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
    isWorking = true;
    const auto threadsToUse = std::thread::hardware_concurrency();
    benchmarkDuration = Benchmark::startBenchmark(threadsToUse, false, config);
    isWorking = false;
}
void Application::startSingleCore()
{
    isWorking = true;
    benchmarkDuration = Benchmark::startBenchmark(1, false, config);
    isWorking = false;

}

void Application::startStressTest()
{
    isWorking = true;
    const auto threadsToUse = std::thread::hardware_concurrency();
    benchmarkDuration = Benchmark::startBenchmark(threadsToUse, true, config);
    isWorking = false;
}


