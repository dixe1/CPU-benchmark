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
#include <atomic>

#include "../includes/Benchmark.h"
#include "../includes/ConfigLoader.h"

class Benchmark
{
private:
    const std::unordered_map<std::string, std::string> config = ConfigLoader::load("../config/config.txt");
    void calculate(size_t threads)
    {
        const uint64_t cycles = std::floor(std::stoi(config.at("cycles")) / threads);

        double j{};
        for (uint64_t i{}; i < cycles; i++)
        {
            volatile double r = std::sin(std::stod(config.at("num")) + j + 1);
            j += 0.001;
        }
    }

public:
    double duration{};

    void startBenchmark(size_t threadsToUse, std::atomic<bool>& isWorking)
    {
        isWorking = true;
        std::vector<std::thread> threads;
        threads.reserve(threadsToUse);

        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i{}; i < threadsToUse; i++)
            threads.emplace_back(&Benchmark::calculate, this, threadsToUse);

        for (auto& thread : threads)
            thread.join();

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration_ = end - start;
        isWorking = false;
        duration = duration_.count();
    };
};
