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
#include <list>

using namespace std;

int main(void) {
	size_t number_count = 15;
	//std::cin >> number_count;
	std::vector<int> numbers{7,2,1,3,8,4,9,1,2,6,5,9,3,8,1};
	/*for (auto& number : numbers) {
		std::cin >> number;
	}*/

	std::vector<int> indexes;
	std::cout << LIS_optimumBottomUp(numbers, indexes) << std::endl;
	std::copy(
		indexes.begin(),
		indexes.end(),
		std::ostream_iterator<int>(std::cout, " ")
	);
}