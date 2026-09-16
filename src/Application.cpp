//
// Created by bartek on 2/27/26.
//
#include <thread>
#include <cmath>

#include "Application.h"
#include "Benchmark.h"
#include "Config.h"

void Application::benchmarkMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), false);
    isBenchmarkRunning = false;

    calculatePoints();
}
void Application::benchmarkSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, false);
    isBenchmarkRunning = false;

    calculatePoints();
}

void Application::stressTestMultiCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(std::thread::hardware_concurrency(), true);
    isBenchmarkRunning = false;
}
void Application::stressTestSingleCore()
{
    isBenchmarkRunning = true;
    benchmarkDuration = Benchmark::startBenchmark(1, true);
    isBenchmarkRunning = false;
}

void Application::calculatePoints()
{
    const double points = static_cast<double>(Config::cycles) / benchmarkDuration * 1e-6;
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

bool Application::getIsBenchmarkRunning() const
{
    return isBenchmarkRunning.load();
}
