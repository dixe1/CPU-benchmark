//
// Created by bartek on 2/14/26.
//
#pragma once
#include <cstddef>
#include <unordered_map>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>

#include "../includes/Benchmark.h"
#include "../includes/ConfigLoader.h"

class Benchmark
{
private:
    const std::unordered_map<std::string, std::string> config = ConfigLoader::load("../config/config.txt");
    void calculate(size_t threads)
    {
        const uint32_t cycles = std::floor(std::stoi(config.at("cycles")) / threads);

        for (uint32_t i{}; i < cycles; i++)
        {
            volatile double r = std::pow(std::stod(config.at("num1")), std::stod(config.at("num2")));
        }
    }

public:
    double startBenchmark(size_t threadsToUse)
    {
        std::vector<std::thread> threads;
        threads.reserve(threadsToUse);

        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i{}; i < threadsToUse; i++)
            threads.emplace_back(&Benchmark::calculate, this, threadsToUse);

        for (auto& thread : threads)
            thread.join();

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        return duration.count();
    };
};
