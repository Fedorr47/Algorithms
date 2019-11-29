#pragma once
#include <vector>
#include <iostream>

using namespace std;

int coast_stairs(vector<int> cost)
{
	int n = cost.size();
	vector<int> ans(n);
	ans[0] = cost[0];
	ans[1] = cost[1];
	if ( n == 1)
		return ans[1];
	if (n == 2)
	{
		auto sum = ans[0] + ans[1];
		return sum > ans[1] ? sum : ans[1];
	}
	if (ans[0] > 0 && ans[1] > 0)
	{
		ans[1] += ans[0];
	}
	for (int i = 2; i < n; ++i)
	{
		auto max_val = max(ans[i - 1], ans[i - 2]);
		max_val += cost[i];
		ans[i] = max_val;
	}
	return ans[n-1];
}

void test_stairs()
{
	//5
	//- 2 - 16 - 13 - 9 - 48
	/*vector<int> stairs_1{ 0, 0, 0, 4, 6, -5 };
	cout << coast_stairs(stairs_1) << endl;


	vector<int> stairs_2{ 3, 4, 10, 10, 0, -6, -10, 0 };
	cout << coast_stairs(stairs_2) << endl;

	vector<int> stairs_3{ 2, -1, -1 };
	cout << coast_stairs(stairs_3) << endl;

	vector<int> stairs_4{ -64, -16, -13, -9, -48 };
	cout << coast_stairs(stairs_4) << endl;*/

	vector<int> stairs;
	int count_stairs = 0;
	int temp_count = 0;
	int cost_by_stair = 0;
	cin >> count_stairs;
	while (temp_count < count_stairs)
	{
		std::cin >> cost_by_stair;
		stairs.push_back(cost_by_stair);
		++temp_count;
	}
	int answer = coast_stairs(stairs);
	if (answer != 0)
	{
		std::string out = std::to_string(count_stairs) + "---> ";
		for (auto& val : stairs)
		{
			out += ": " + std::to_string(val);
		}
		cout << out;
	}
	cout << answer;
}