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
//#include "Multiply.h"

using namespace std;

struct S {
	std::vector<int> a, b;
};

struct T {
	std::array<int, 2> a, b;
};

struct A { int i, j; };
struct B { A a1, a2; };
int main() {
	B b1 = { {1, 2}, {3, 4} };
	B b2 = { 1, 2, 3, 4 }; // brace elision
	B b3 = { {1, 2} }; // clause omission
	B b4 = { {1}, {2} };
}

