#pragma once
#define RANGE 255  

void countSort(int* arr, size_t n)
{
	// The output character array  
	// that will have sorted arr  
	int *output = new int[n];

	// Create a count array to store count of inidividul  
	// characters and initialize count array as 0  
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count)/sizeof(count[0]));

	// Store count of each character  
	for (i = 0; i < n; ++i)
		++count[arr[i]];

	// Change count[i] so that count[i] now contains actual  
	// position of this character in output array  
	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	// Build the output character array  
	for (i = 0; i < n; ++i)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	for (i = 0; i < n; ++i)
		arr[i] = output[i];
}

#include <iostream>
#include <string>

void example_countSort()
{
	int n = 0;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	countSort(arr, n);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
