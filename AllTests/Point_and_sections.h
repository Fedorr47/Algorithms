#pragma once

#include <vector>

#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <functional>
#include <random>
#include <ctime>
#include <iostream>
#include <chrono>
#include <string>


void quickSort(
	int** sections,
	int left,
	int right,
	char sort
)	
{
	int i = left, j = right;
	int tmp, tmp1;
	int pivot = sections[(left + right) / 2][sort];

	/* partition */
	while (i <= j) {
		while (sections[i][sort] < pivot)
			i++;
		while (sections[j][sort] > pivot)
			j--;
		if (i <= j) {
			tmp = sections[i][0]; tmp1 = sections[i][1];
			sections[i][0] = sections[j][0]; sections[i][1] = sections[j][1];
			sections[j][0] = tmp; sections[j][1] = tmp1;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(sections, left, j, sort);

	if (i < right)
		quickSort(sections, i, right, sort);

}
int binarySearch(int** vec, size_t size_vec, int value, int sort)
{
	int left = 0;
	int right = size_vec;
	int mediane = -1;
	char shift = 1;
	std::function<bool(int&)> mediane_op;
	auto return_wrapper = [&](bool exists = true)
	{
		if (sort == 0 && mediane == size_vec && vec[mediane][sort] <= value)
			++mediane;
		else if (sort == 1 && mediane == size_vec && vec[mediane][sort] < value)
			++mediane;
		else if (!exists)
			if (vec[mediane][sort] < value)
				++mediane;
		return mediane;
	};
	while (left <= right)
	{
		mediane = left + (right - left) / 2;
		if (vec[mediane][sort] == value)
		{
			if (sort == 0 && mediane + 1 <= size_vec && vec[mediane + 1][sort] == value)
				mediane_op = [&](int& med) -> bool {
				if (vec[med][sort] == value)
				{
					++med;
					return true;
				}
				return false;
			};
			else if (sort == 1 && mediane - 1 >= 0 && vec[mediane - 1][sort] == value)
				mediane_op = [&](int& med) -> bool {
				if (vec[med][sort] == value)
				{
					--med; 
				}
				if (vec[med][sort] != value)
				{
					++med;
					return false;
				}
				return true;
			};
			else
			{
				if (sort == 0)
					++mediane;
				return return_wrapper();
			}
			while (mediane != size_vec && mediane > 0 && mediane_op(mediane))
			{
			}
			return return_wrapper();
		}
		else if (vec[mediane][sort] > value)
		{
			right = mediane - 1;
		}
		else
		{
			left = mediane + 1; 
		}
	}
	mediane = mediane == -1 ? 0 : return_wrapper(false);
	return mediane;
}

int* get_enter_points(
	int** sections,
	int sections_size,
	int* points,
	int points_size
)
{
	int* pointers_enter = new int[points_size];
	quickSort(sections, 0, sections_size-1, 0);
	for (int i = 0; i < points_size; ++i)
	{
		pointers_enter[i] = binarySearch(sections, sections_size - 1, points[i], 0);
		std::cout << "pointers_enter[" << i << "] = " << pointers_enter[i] << std::endl;
	}
	quickSort(sections, 0, sections_size - 1, 1);
	for (int i = 0; i < points_size; ++i)
	{
		pointers_enter[i] -= binarySearch(sections, sections_size - 1, points[i], 1);
		std::cout << "pointers_enter[" << i << "] = " << pointers_enter[i] << std::endl;;
	}
	return pointers_enter;
}
/*
6 6
0 3
1 3
2 3
3 4
3 5
3 6
1 2 3 4 5 6
(2;3;6;3;2;1)
----------------------------
10 5
-2 3
0 3
-1 0
-1 3
0 1
-2 -1
1 3
2 3
1 2
2 3
-3 -1 0 2 3
(0;4;5;7;6)
----------------------------
6 6
2 3
2 5
3 5
2 7
5 7
3 7
1 2 3 5 6 7
(0;3;5;5;3;3)
----------------------------
1 3
-10 10
-100 100 0
(0;0;1)
*/
//int main() {
//
//	int** arr;    // (1)
//	int size_mas = 0;
//	int size_points = 0;
//	std::cin >> size_mas;
//	std::cin >> size_points;
//	// создание
//	arr = new int*[size_mas];    // массив указателей (2)
//	for (int i = 0; i < size_mas; i++) {   // (3)
//		arr[i] = new int[2];     // инициализация указателей
//	}
//	int* points = new int[size_points];
//
//	for (int i = 0; i < size_mas; ++i)
//	{
//		std::cin >> arr[i][0] >> arr[i][1];
//	}
//	for (int i = 0; i < size_points; ++i)
//	{
//		std::cin >> points[i];
//	}
//
//	int* points_enter = get_enter_points(arr, size_mas, points, size_points);
//
//	for (int i = 0; i < size_points; ++i)
//	{
//		std::cout << points_enter[i];
//		std::cout << std::endl;
//	}
//
//	// уничтожение
//	for (int i = 0; i < size_mas; i++) {
//		delete[] arr[i];
//	}
//	delete[] arr;
//	delete[] points;
//	delete[] points_enter;
//
//	return 0;
//}

