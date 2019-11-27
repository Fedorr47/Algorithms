#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int,int>> back_pack(map<int, int> items, size_t bcapacity)
{
	
	vector<pair<int, int>> full_back_pack;
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
					full_back_pack[i] = pair<int,int>(
						std::max<int>(
							{
								full_back_pack[i].first,
								full_back_pack[i - it->first].first + it->first
							}),
						std::max<int>(
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

void test_back_pack()
{
	map<int, int> test_vec = { {6, 30},{3, 14},{4, 16}, {2, 9} };
	back_pack(test_vec, 10);
}
