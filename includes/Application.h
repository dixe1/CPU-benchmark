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
    std::atomic<bool> isWorking = true;
    std::unordered_map<std::string, std::string> config;

    void loadConfig(const std::string& fileName);


    void startMultiCore();
    void startSingleCore();
    void startStressTest();
};