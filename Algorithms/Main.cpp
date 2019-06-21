#include <iostream>
#include <chrono>
#include <string>

#include "General/Fibonachi.h"
#include "General/GCD.h"
#include "Greedy/MinPoints.h"
#include "Greedy/BackPackTask.h"
#include "General/k_num.h"
#include "Greedy/Hafman_simple.h"
#include "Greedy/PriorQueue.h"
#include "DivideConquer/BinaryFind.h"
#include "DivideConquer/Inverse.h"
#include "DivideConquer/Point_and_sections.h"
#include "DivideConquer/Quick_sort.h"
#include "DivideConquer/Inverse_recursive.h"
#include "DivideConquer/HeapSort.h"

using namespace std;

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	cout << "Sorted array is \n";
	printArray(arr, n);
}


