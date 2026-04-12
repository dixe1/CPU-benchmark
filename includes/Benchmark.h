//
// Created by bartek on 2/14/26.
//
#pragma once
#include <atomic>
#include <unordered_map>
#include <any>

class Benchmark
{
private:
    static void calculate(size_t threads, bool stressTest, const std::unordered_map<std::string, std::any>& config);

    // Add results from all threads
    // To prevent compiler optimizations
    static std::atomic<int> outputNumbers;

public:
    static double startBenchmark(size_t threadsToUse, bool stressTest, const std::unordered_map<std::string, std::any>& config);
};