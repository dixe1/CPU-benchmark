//
// Created by bartek on 2/27/26.
//

#pragma once
#include <string>
#include <atomic>
#include <unordered_map>

class Application
{
private:
    double benchmarkDuration{};
    int benchmarkPoints{};
    std::unordered_map<std::string, std::string> config;
public:
    std::atomic<bool> isBenchmarkRunning = true;

    int loadConfig(const std::string& fileName);


    void startMultiCore();
    void startSingleCore();
    void startStressTest();

    void calculatePoints();

    double getBenchmarkDuration() const;
    int getBenchmarkPoints() const;
    const std::unordered_map<std::string, std::string>& getConfig() const;
};