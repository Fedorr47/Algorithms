#pragma once
#include <cassert>
#include <array>
#include <vector>


class Fibonacci final {
public:
	static int64_t get(int64_t n) {
		assert(n >= 0);
		if (n == 1)
			return 1;
		int64_t fib_prev = 0;
        int64_t fib_this = 1;
		for (int64_t i = 2; i <= n; ++i)
		{
			auto new_val = fib_this + fib_prev;
            fib_prev = fib_this;
            fib_this = new_val;
		}
		n = fib_this;
		return n;
	}
	static int64_t get_last_digit(int64_t n) {
		assert(n >= 1);
		std::array<int64_t, 2> fib_array = { 0,1 };
		for (int64_t i = 2; i <= n; ++i)
		{
			auto new_val = ((fib_array[0] % 10) + (fib_array[1] % 10)) % 10;
			fib_array[0] = fib_array[1];
			fib_array[1] = new_val;
		}
		n = fib_array[1];
		return n;
	}
//https://ru.wikipedia.org/wiki/%D0%9F%D0%B5%D1%80%D0%B8%D0%BE%D0%B4_%D0%9F%D0%B8%D0%B7%D0%B0%D0%BD%D0%BE
	static int64_t get_remainder(int64_t n, int64_t m) {
		assert(n >= 1);
		assert(m >= 2);
	
		int64_t f_2,f_1;
		f_2 = 1;
		f_1 = 2;

		std::vector<int64_t> pisano_vector = {0,1};
		do
		{
			pisano_vector.push_back(f_2%m);
			int64_t new_val = f_2%m + f_1%m;
			f_2 = f_1%m;
			f_1 = new_val%m;	
		} while (!((*(pisano_vector.end() - 1) == 1)
			  && (*(pisano_vector.end() - 2) == 0)));

		auto ret_val = pisano_vector[n%(pisano_vector.size()-2)];

		return ret_val;
	}
};

//std::cin >> n;
// Fibonachi test
//auto start = std::chrono::high_resolution_clock::now();
//std::cout << Fibonacci::get(3000000) << std::endl;
//auto finish = std::chrono::high_resolution_clock::now();
//std::chrono::duration<double> elapsed = finish - start;
//std::cout << "time to count = " << elapsed.count();
//std::cout << Fibonacci::get_remainder(10,2) << std::endl;