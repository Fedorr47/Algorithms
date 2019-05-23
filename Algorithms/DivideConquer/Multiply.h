#pragma once

int multiply(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return 0;
	}
	else if (x == 1)
	{
		return y;
	}
	else if (y == 1)
	{
		return x;
	}
	int rec = multiply(x, y>>1);
	if (y & 0x1)
	{
		return x + (rec<<1);
	}
	else
	{
		return rec<<1;
	}
}

#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

//#ifdef ENVIRONMENT64
//uint64_t size = 64;
//uint64_t mask = 0x8000000000000000;
//#else
//uint32_t size = 32;
//uint32_t mask = 0x80000000;
//#endif

int get_bit_lentgh(uint32_t val)
{
	uint32_t size = 32;
	uint32_t mask = 0x80000000;
	while (!(val&mask))
	{
		mask >>= 1;
		--size;
	}
	return size;
}

int karatsuba(uint32_t x, uint32_t y)
{
	int size_x = get_bit_lentgh(x);
	int size_y = get_bit_lentgh(y);
	int n_size = std::max(size_x, size_y);
	if (n_size == 1)
		return x * y;
	int x_l = 
}