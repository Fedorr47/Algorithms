#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
vector<pair<T,T>> back_pack(map<T, T> items, size_t bcapacity)
{
	
	vector<pair<T, T>> full_back_pack;
	for (size_t i = 0; i <= bcapacity; ++i)
	{
		full_back_pack.push_back({0,0});
	}
	auto items_end = items.cend();
	auto items_beg = items.cbegin();

	for (size_t i = 1; i <= bcapacity; ++i)
	{
		for (auto it = items_beg; it != items_end; ++it)
		{
			if (it->first <= i)
			{
				if (full_back_pack[i].first <= it->first)
				{
					full_back_pack[i] = pair<T,T>(
						std::max<T>(
							{
								full_back_pack[i].first,
								full_back_pack[i - it->first].first + it->first
							}),
						std::max<T>(
						{
							full_back_pack[i].second,
							full_back_pack[i - it->first].second + it->second
						}
						)
					);
				}
			}
		}
	}
	return std::move(full_back_pack);
}

int back_pack_distinct(map<int, int> items, size_t bcapacity)
{
	std::vector<std::vector<int>> table(items.size() + 1);
	for (auto& vec : table)
	{
		for (size_t i = 0; i < bcapacity + 1; ++i)
			vec.emplace_back(0);
	}

	auto items_end = items.cend();
	auto items_beg = items.cbegin();

	int i = 1;
	for (auto it = items_beg; it != items_end; ++it)
	{ // 3
		for (int j = 1; j < bcapacity + 1; ++j) { 
			table[i][j] = table[i - 1][j]; 
			if (it->first > j) 
				continue;
			int candidate = table[i - 1][j - it->first] + it->second; 
			if (candidate > table[i][j])
				table[i][j] = candidate;
		}
		++i;
	}

	return table[items.size()][bcapacity];
}

void test_back_pack()
{
	//map<int, int> test_vec = { {6, 30},{3, 14},{4, 16}, {2, 9} };
	//auto result = back_pack_distinct(test_vec, 10);
	int capacity_backpack = 0;
	int count_values = 0;
	int weight = 0;
	map<int, int> test_vec;
	cin >> capacity_backpack;
	cin >> count_values;
	while (count_values > 0)
	{
		std::cin >> weight;
		test_vec.insert({ weight, weight });
		--count_values;
	}
	cout << back_pack_distinct(test_vec, capacity_backpack) << endl;
	//for (auto& pair_res : result)
	//{
	//	cout << "Wieght = " << pair_res.first 
	//		<< " | Cost = " << pair_res.second
	//		<< endl;
	//}
}
