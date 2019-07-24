#include <vector>
#include <iostream>
#include <algorithm>

int editing_distance_td(
	int,
	int,
	const std::string&,
	const std::string&,
	std::vector<std::vector<int>>&
);

int editing_distance_bu(
	int,
	int,
	const std::string&,
	const std::string&,
	std::vector<std::vector<int>>&
);

int editing_distance(
	const std::string& first,
	const std::string& second,
	char rule = 'd'
)
{
	int _distance = 0;
	size_t first_len = first.size()+1;
	size_t second_len = second.size()+1;

	std::vector<std::vector<int>> table_distance(first_len);
	for (auto& vec : table_distance)
	{
		for (size_t i = 0; i < second_len; ++i)
			vec.emplace_back(0);
	}
	if (rule != 'd' && rule != 'u')
		rule = 'd';
	if (rule == 'd')
	{
		_distance = editing_distance_td(
			first_len-1,
			second_len-1,
			first,
			second,
			table_distance
		);
	}
	else if (rule == 'u')
	{
		_distance= editing_distance_bu
		(
			first_len-1,
			second_len-1,
			first,
			second,
			table_distance
		);
	}

	return _distance;
}

int editing_distance_td(
	int i,
	int j,
	const std::string& A,
	const std::string& B,
	std::vector<std::vector<int>>& table
)
{
	int difference = 0;
	if (i == 0)
		table[i][j] = j;
	else if (j == 0)
		table[i][j] = i;
	else
	{
		int ins = editing_distance_td(i, j - 1, A, B, table) + 1;
		int del = editing_distance_td(i - 1, j, A, B, table) + 1;
		difference = [&]() -> int {return A[i] == B[j] ? 0 : 1; }();
		int sub = editing_distance_td(i - 1, j - 1, A, B, table) + difference;
		table[i][j] = std::min({ ins,del,sub });
	}
	return table[i][j];
}

int editing_distance_bu(
	int n,
	int m,
	const std::string& A,
	const std::string& B,
	std::vector<std::vector<int>>& table
)
{
	int difference = 0;

	for (int i = 0; i <= n; ++i)
		table[i][0] = i;
	for (int j = 0; j <= m; ++j)
		table[0][j] = j;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			difference = [&]() -> int {return A[i-1] == B[j-1] ? 0 : 1; }();
			table[i][j] = std::min({ 
				table[i-1][j]+1,
				table[i][j-1]+1,
				table[i-1][j-1]+difference});
		}
	return table[n][m];
}

/*
std::string a = "short";
	std::string b = "ports";
	cout << "editing_distance = " << editing_distance(b, a, 'u') << endl;
*/