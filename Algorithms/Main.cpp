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

using namespace std;

int main() {
	int* arr = new int[7] {6,4,3,2,1,7,8};
	quickSort(arr, 0, 6);
	delete[] arr;
	return 0;
}



