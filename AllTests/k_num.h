#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

void num_k()
{
    long n, k, sum, dx;
    std::cin >> n;
    for (k = 2; (k + 1) * k / 2 <= n; ++k);
    k--;
    sum = (2 + k - 1) * k / 2;
    dx = n - sum;
    std::cout << k << std::endl;
    for (int i = 1; i < k; i++) 
        std::cout << i << " ";
    std::cout << k + dx << std::endl;
}