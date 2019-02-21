#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
    int weight;
    int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
    double value = 0.0;

    std::sort(items.begin(), items.end(), [&](Item item1, Item item2)
    {
        return (item1.value/(double)item1.weight) > (item2.value /(double)item2.weight);
    });

    // take items while there is empty space in knapsack
    for (auto &item : items) {
        if (capacity > item.weight) {
            // can take full item and continue
            capacity -= item.weight;
            value += item.value;          
        }
        else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }
    return value;
}

void backpack_function(void) {
    int number_of_items{ 2 };
    int knapsack_capacity{ 6 };
    //std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    //for (int i = 0; i < number_of_items; i++) {
    //    std::cin >> items[i].value >> items[i].weight;
    //}
    items[0].value = 5; items[0].weight = 12;
    items[1].value = 6; items[1].weight = 15;

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;
}