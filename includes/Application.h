//
// Created by bartek on 2/27/26.
//

#pragma once
#include <any>
#include <atomic>
#include <string>
#include <unordered_map>

class Application
{
  private:
    double benchmarkDuration{};
    int benchmarkPoints{};
    std::atomic<bool> isBenchmarkRunning = true;

    void calculatePoints();

  public:
    void benchmarkMultiCore();
    void benchmarkSingleCore();
    void stressTestMultiCore();
    void stressTestSingleCore();

    double getBenchmarkDuration() const;
    int getBenchmarkPoints() const;
    const std::unordered_map<std::string, std::any>& getConfig() const;
    bool getIsBenchmarkRunning() const;
};