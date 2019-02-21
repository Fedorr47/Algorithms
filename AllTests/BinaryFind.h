#pragma once
#include <vector>

template <class T>
int binarySearch(std::vector<T>& vec, T value)
{
	int left = 0;
	int right = vec.size()-1;
	while(left <= right)
	{
		int mediane = left + (right - left) / 2;
		if (vec[mediane] == value)
		{
			return mediane;
		}
		else if (vec[mediane] > value)
		{
			right = mediane - 1;
		}
		else
		{
			left = mediane + 1;
		}
	}
	return -1;
}

//size_t number_count;
//std::cin >> number_count;
//std::vector<int> numbers(number_count);
//for (auto &number : numbers) {
//	std::cin >> number;
//}
//assert(std::is_sorted(numbers.begin(), numbers.end()));
//
//size_t query_count;
//std::cin >> query_count;
//while (query_count-- > 0) {
//	int number;
//	std::cin >> number;
//	std::cout << binarySearch(numbers, number) << " ";
//}
//std::cout << std::endl;