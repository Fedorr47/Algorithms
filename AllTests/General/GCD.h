#pragma once
#include <cassert>
#include <array>
#include <vector>

class GCD final {
public:
	template <class Int>
	static Int gcd(Int a, Int b)
	{
		assert(a > 0 && b > 0);
		Int current_gcd = 1;
        
		if (a == 0)
			return b;
		if (b == 0)
			return a;

        if (b > a)
        {
            std::swap(a, b);
        }

		while (b > 0)
		{	
		    a = a % b;
            std::swap(a, b);
		}

		current_gcd = a;
		return current_gcd;
	}
};

// GCD
//std::cout << GCD::gcd(14159572, 14159572) << std::endl;