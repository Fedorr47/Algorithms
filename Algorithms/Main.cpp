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
#include "DivideConquer/CountingSort.h"
#include "Dynamic/LisBottomUp.h"

using namespace std;

int main() {
	int a[14]{ 3,4,5,1,2,3,4,5,6,7,8,9,11,12 };
	int res;
	int* list_lis;
	res = LISBottomUp(a, 14, (int**)&list_lis);
	std::cout << "Length of lis is - " << res << std::endl;
	printArray(list_lis, res);
}