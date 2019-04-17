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

using namespace std;

std::string gap = std::string(40, '-');
void print_vector(std::vector<int64_t>& vec)
{
	int index = 0;
	std::cout << gap << std::endl;
	std::cout << "Massive output" << std::endl;
	for (int i : vec)
	{
		std::cout << "index(" << index++ << ")" << " = " << i << std::endl;
	}
}

int main() {

}



