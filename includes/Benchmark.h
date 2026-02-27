//
// Created by bartek on 2/14/26.
//
#pragma once


class Benchmark
{
private:
    static double calculate(const size_t threads, const bool stressTest, const std::unordered_map<std::string, std::string>& config);

public:
    static double startBenchmark(size_t threadsToUse, bool stressTest, const std::unordered_map<std::string, std::string>& config);
};