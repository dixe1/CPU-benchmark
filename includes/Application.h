//
// Created by bartek on 2/27/26.
//

#pragma once
#include <string>
#include <atomic>
#include <unordered_map>
#include <any>

class Application
{
private:
    double benchmarkDuration{};
    int benchmarkPoints{};
    std::unordered_map<std::string, std::any> config;
    std::atomic<bool> isBenchmarkRunning = true;

    void calculatePoints();
public:

    int loadConfig(const std::string& fileName);


    void benchmarkMultiCore();
    void benchmarkSingleCore();
    void stressTestMultiCore();
    void stressTestSingleCore();

    double getBenchmarkDuration() const;
    int getBenchmarkPoints() const;
    const std::unordered_map<std::string, std::any>& getConfig() const;
    bool getIsBenchmarkRunning() const;
};