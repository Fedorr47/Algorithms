#include <iostream>
#include <chrono>
#include <string>

#include "Fibonachi.h"
#include "GCD.h"
#include "MinPoints.h"
#include "BackPackTask.h"
#include "k_num.h"
#include "Hafman_simple.h"
#include "PriorQueue.h"
#include "BinaryFind.h"
#include "Invariant.h"
#include "RecursiveMergeSort.h"
#include "Point_and_sections.h"

using namespace std;

void print_array(int** arr, size_t size_)
{
	std::cout << "Print array" << std::endl;
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << arr[i][j];
			if (j < 1)
				std::cout << ":";
		}
		std::cout << std::endl;
	}
}

int main() {
	
	int** arr;   
	int size_mas = 0;
	int size_points = 0;
	std::cin >> size_mas;
	std::cin >> size_points;
	// создание
	arr = new int* [size_mas];    
	for (int i = 0; i < size_mas; i++) {  
		arr[i] = new int[2];    
	}
	int* points = new int[size_points];

	for (int i = 0; i < size_mas; ++i)
	{
		std::cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < size_points; ++i)
	{
		std::cin >> points[i];
	}

	int* points_enter = get_enter_points(arr, size_mas, points, size_points);

	for (int i = 0; i < size_points; ++i)
	{
		std::cout << points_enter[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size_mas; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] points;
	delete[] points_enter;

	return 0;
}



