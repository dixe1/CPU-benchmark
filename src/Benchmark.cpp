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
#include <any>

#include "Benchmark.h"

// outputNumbers is static that's why do this
std::atomic<int> Benchmark::outputNumbers{};

void Benchmark::calculate(const size_t threads, const bool stressTest, const std::unordered_map<std::string, std::any>& config)
{
    const auto cycles = std::any_cast<long long>(config.at("cycles")) / threads;
    const auto num = std::any_cast<double>(config.at("num"));

    double j{};
    double sum{};

    // Stress test
    if (stressTest)
    {
        while (true)
        {
            const volatile double r = std::sin(num + j + 1);
            sum += r;
            j += 0.001;
        }
    }

    // Normal benchmark
    else
    {
        for (uint64_t i{}; i < cycles; i++)
        {
            const volatile double r = std::sin(num + j + 1);
            sum += r;
            j += 0.001;
        }
    }
    outputNumbers += static_cast<int>(sum);
}

double Benchmark::startBenchmark(size_t threadsToUse, bool stressTest,const std::unordered_map<std::string, std::any>& config)
{
    std::vector<std::thread> threads;
    threads.reserve(threadsToUse);

    const auto start = std::chrono::high_resolution_clock::now();
    for (size_t i{}; i < threadsToUse; i++)
        threads.emplace_back(&Benchmark::calculate, threadsToUse, stressTest, std::ref(config));

    for (auto& thread : threads)
        if (thread.joinable())
            thread.join();

    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end - start;
    return duration.count();
}