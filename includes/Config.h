//
// Created by bartek on 9/16/26.
//

#pragma once

#include <cstdint>

namespace Config
{
    inline constexpr uint64_t cycles = 7000000000;
    inline constexpr double num = 3.123141;

    static_assert(cycles >= 50, "value of cycles must be at least 400!");
}