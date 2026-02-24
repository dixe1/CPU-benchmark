//
// Created by bartek on 2/24/26.
//
#include <cstddef>
#include <unordered_map>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <atomic>

#include "../includes/Benchmark.h"

double Benchmark::calculate(const size_t threads, const bool stressTest) const
{
    const uint64_t cycles = std::floor(std::stoull(config.at("cycles")) / threads);
    const double num = std::stod(config.at("num"));

    double j{};
    double sum{};

    if (stressTest)
    {
        while (true)
        {
            const volatile double r = std::sin(num + j + 1);
            sum += r;
            j += 0.001;
        }
    }
    else
    {
        for (uint64_t i{}; i < cycles; i++)
        {
            const volatile double r = std::sin(num + j + 1);
            sum += r;
            j += 0.001;
        }
    }
    return sum; // To stop compiler optimising code
}

void Benchmark::startBenchmark(size_t threadsToUse, std::atomic<bool>& isWorking, const bool stressTest)
{
    isWorking = true;
    std::vector<std::thread> threads;
    threads.reserve(threadsToUse);

    const auto start = std::chrono::high_resolution_clock::now();
    for (size_t i{}; i < threadsToUse; i++)
        threads.emplace_back(&Benchmark::calculate, this, threadsToUse, stressTest);

    for (auto& thread : threads)
        thread.join();

    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration_ = end - start;
    duration = duration_.count();
    isWorking = false;
}