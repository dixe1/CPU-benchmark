//
// Created by bartek on 2/27/26.
//
#include <thread>
#include <cmath>
#include <any>

#include "Application.h"
#include "ConfigLoader.h"
#include "Benchmark.h"

int Application::loadConfig(const std::string &fileName)
{
    config = ConfigLoader::load(fileName);

    // ConfigLoader returns empty list if cannot find file
    if (config.empty())
        return 1;

    return 0;
}

void Application::benchmarkMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), false, config);
    isBenchmarkRunning = false;

    calculatePoints();
}
void Application::benchmarkSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, false, config);
    isBenchmarkRunning = false;

    calculatePoints();
}

void Application::stressTestMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), true, config);
    isBenchmarkRunning = false;
}
void Application::stressTestSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, true, config);
    isBenchmarkRunning = false;
}

void Application::calculatePoints()
{
    const auto cycles = std::any_cast<long long>(config.at("cycles"));
    const double points = static_cast<double>(cycles) / benchmarkDuration * 1e-6;
    benchmarkPoints = static_cast<int>(std::round(points));
}

double Application::getBenchmarkDuration() const
{
    return benchmarkDuration;
}

int Application::getBenchmarkPoints() const
{
    return benchmarkPoints;
}

const std::unordered_map<std::string, std::any>& Application::getConfig() const
{
    return config;
}

bool Application::getIsBenchmarkRunning() const
{
    return isBenchmarkRunning.load();
}
