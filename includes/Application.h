//
// Created by bartek on 2/27/26.
//

#pragma once
#include <string>
#include <atomic>
#include <unordered_map>

class Application
{
public:
    double benchmarkDuration{};
    int benchmarkPoints{};
    std::atomic<bool> isBenchmarkRunning = true;
    std::unordered_map<std::string, std::string> config;

    int loadConfig(const std::string& fileName);


    void startMultiCore();
    void startSingleCore();
    void startStressTest();

    void calculatePoints();
};