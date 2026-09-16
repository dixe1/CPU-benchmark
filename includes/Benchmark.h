//
// Created by bartek on 2/14/26.
//
#pragma once
#include <any>
#include <atomic>
#include <unordered_map>

class Benchmark
{
  private:
    static void calculate(size_t threads, bool stressTest);

    // Add results from all threads
    // To prevent compiler optimizations
    static std::atomic<int> outputNumbers;

  public:
    static double startBenchmark(size_t threadsToUse, bool stressTest);
};