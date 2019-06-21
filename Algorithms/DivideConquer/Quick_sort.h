#pragma once

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
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

void quickSort(int arr[], int low, int high)
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