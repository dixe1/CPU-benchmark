//
// Created by bartek on 2/24/26.
//
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <thread>
#include <vector>

#include "Benchmark.h"
#include "Config.h"

// outputNumbers is static that's why do this
std::atomic<int> Benchmark::outputNumbers{};

void Benchmark::calculate(const size_t threads, const bool stressTest)
{

    double j{};
    double sum{};

    // Stress test
    if (stressTest)
    {
        while (true)
        {
            const volatile double r = std::sin(Config::num + j + 1);
            sum += r;
            j += 0.001;
        }
    }

    // Normal benchmark
    else
    {
        for (uint64_t i{}; i < Config::cycles / threads; i++)
        {
            const volatile double r = std::sin(Config::num + j + 1);
            sum += r;
            j += 0.001;
        }
    }
    outputNumbers += static_cast<int>(sum);
}

double Benchmark::startBenchmark(size_t threadsToUse, bool stressTest)
{
    std::vector<std::thread> threads;
    threads.reserve(threadsToUse);

    const auto start = std::chrono::high_resolution_clock::now();
    for (size_t i{}; i < threadsToUse; i++)
        threads.emplace_back(&Benchmark::calculate, threadsToUse, stressTest);

    for (auto& thread : threads)
        if (thread.joinable())
            thread.join();

    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end - start;
    return duration.count();
}