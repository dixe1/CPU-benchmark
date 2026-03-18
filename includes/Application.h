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
    std::atomic<bool> isBenchmarkRunning = true;

    void calculatePoints();
public:

    int loadConfig(const std::string& fileName);


    void startMultiCore();
    void startSingleCore();
    void startStressTest();

    double getBenchmarkDuration() const;
    int getBenchmarkPoints() const;
    const std::unordered_map<std::string, std::string>& getConfig() const;
    bool getIsBenchmarkRunning() const;
};