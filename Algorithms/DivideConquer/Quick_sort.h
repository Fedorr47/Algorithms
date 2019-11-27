#pragma once

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
char partition(char arr[], char low, char high)
{
	// pivot (Element to be placed at right position)
	int pivot = arr[high];

	int i = low;  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			std::swap(arr[i], arr[j]);
			++i;
		}
	}

	std::swap(arr[i], arr[high]);
	return i;
}

void quickSort(char arr[], char low, char high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);  // Before pi
		quickSort(arr, pi + 1, high); // After pi
	}
}

void test_quick_sort()
{
	char a[6] = { 9,3,4,5,2,7 };
	quickSort(a, 0, 5);
}