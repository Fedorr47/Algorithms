#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>

void merge(long long* arr, long long l, long long m, long long r, long long& invariant_count)
{
	long long i, j, k;
	long long n1 = m - l + 1;
	long long n2 = r - m;

	long long* L = new long long[n1];
	long long* R = new long long[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		std::cout << "L[" << i << "]" << " = " << L[i] << "\n";
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
		std::cout << "R[" << j << "]" << " = " << R[j] << "\n";
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			invariant_count += n1 - i;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
	std::cout << std::endl;
}

void merge_sort(long long* arr, long long l, long long r, long long& invariant_count)
{
	std::cout << "Merge_sort start - l=" << l << " r=" << r << std::endl;
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		merge_sort(arr, l, m, invariant_count);
		merge_sort(arr, m + 1, r, invariant_count);

		std::cout << "Merge - l=" << l << " m=" << m << " r=" << r << std::endl;
		merge(arr, l, m, r, invariant_count);
	}
	std::cout << "Merge_sort end   - l=" << l << " r=" << r << std::endl;
}

//int main() {
//	long long count_value{ 0 };
//	std::cin >> count_value;
//	long long* arr = new long long[count_value] {0};
//	long long i = 0;
//	while (count_value)
//	{
//		--count_value;
//		std::cin >> arr[i];
//		++i;
//	}
//	long long invariant_count = 0;
//	merge_sort(arr, 0, i - 1, invariant_count);
//	std::cout << invariant_count << std::endl;
//	delete[] arr;
//}