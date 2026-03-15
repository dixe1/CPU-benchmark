//
// Created by bartek on 3/15/26.
//

#include "../includes/GetCPUName.h"

#include <iostream>
#include <cstring>

#ifdef _WIN32
#include <intrin.h>
void cpuid(int info[4], int leaf) {
    __cpuid(info, leaf);
}
#else
#include <cpuid.h>
void cpuid(int info[4], int leaf) {
    __cpuid(leaf, info[0], info[1], info[2], info[3]);
}
#endif

std::string getCPUName()
{
    char brand[49] = {};
    int info[4];

    for (int i = 0; i < 3; i++) {
        cpuid(info, 0x80000002 + i);
        memcpy(brand + i * 16, info, 16);
    }

    return brand;
}
