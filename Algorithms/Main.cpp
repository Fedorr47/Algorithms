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
	long long* arr = new long long[7] {7,6,4,5,2,3,1};
	long long invariant_count = 0;
	merge_sort(arr, 0, 7, invariant_count);
	std::cout << invariant_count << std::endl;
	delete[] arr;
	return 0;
}



