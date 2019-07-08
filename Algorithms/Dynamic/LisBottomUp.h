#pragma once

#define max(a,b) a > b ? a : b

int LISBottomUp(int arr[], size_t n)
{
	int *lis = new int[n];
	lis[0] = 1; 
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}
	delete[] lis;
	return ans;
}

int LISBottomUp(int arr[], size_t n, int** ans_arr)
{
	int* lis = new int[n];
	int* prev_ = new int[n];
	lis[0] = 1;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1; 
		prev_[i] = -1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev_[i] = j;
			}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}	
	*ans_arr = new int[ans];
	int k = 1;
	for (size_t i = 2; i < n; ++i)
	{
		if (lis[i] > lis[k])
			k = i;
	}
	int j = ans-1;
	while (k > 0)
	{
		(*ans_arr)[j] = arr[k];
		j -= 1;
		k = prev_[k];
	}
	delete[] prev_;
	delete[] lis;
	return ans;
}

int LISBottomUp1(int arr[], size_t n, int** ans_arr)
{
	int* lis = new int[n];
	lis[0] = 1;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}
	*ans_arr = new int[ans];
	int k = 1;
	for (size_t i = 2; i < n; ++i)
	{
		if (lis[i] > lis[k])
			k = i;
	}
	int j = ans - 1;
	int i = ans, z = k;
	while (k > 0)
	{
		(*ans_arr)[j] = arr[k];
		j -= 1;
		while (lis[k] != i-1 && k > 0)
		{
			--k;
		}
		--i;
	}
	delete[] lis;
	return ans;
}

int get_length_of_longest_divisible_subsequence(const std::vector<int>& numbers)
{
	size_t n = numbers.size();
	std::vector<int> lis(n);
	lis[0] = 1;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (numbers[i] > numbers[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}
	lis.clear();
	return ans;
}

int LISBottomUpLower(
	const std::vector<int>& numbers,
	std::vector<int>& indexes
)
{
	size_t n = numbers.size();
	std::vector<int> lis(n);
	lis[n-1] = 1;
	int min_val = 0;
	for (int i = n-2; i >= 0; --i)
	{
		lis[i] = 1;
		for (int j = n-1; j > i  ; --j)
			if (numbers[i] >= numbers[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}

	indexes.resize(ans);
	int k = 1;
	for (size_t i = 0; i < n; ++i)
	{
		if (lis[i] >= lis[k])
			k = i;
	}
	int j = 0;
	int i = ans, z = k;
	while (k < n)
	{
		indexes[j] = k+1;
		j += 1;
		while (k < n - 1 && lis[k] != i - 1)
		{
			++k;
		}
		if (k == n - 1)
		{
			indexes[j] = k+1;
			break;
		}
		--i;
	}
	lis.clear();
	return ans;
}


// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int LIS_optimumBottomUp(std::vector<int>& v, std::vector<int>& indexes)
{
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {

		// new smallest value 
		if (v[i] < tail[0])
			tail[0] = v[i];

		// v[i] extends largest subsequence 
		else if (v[i] > tail[length - 1])
			tail[length++] = v[i];

		// v[i] will become end candidate of an existing 
		// subsequence or Throw away larger elements in all 
		// LIS, to make room for upcoming grater elements 
		// than v[i] (and also, v[i] would have already 
		// appeared in one of LIS, identify the location 
		// and replace it) 
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
	}

	return length;
}

int LIS_optimumBottomUp1(
	const std::vector<int>& numbers,
	std::vector<int>& indexes
)
{
 	size_t n = numbers.size();
	std::vector<int64_t> lis(n);
	lis[0] = int64_t(1) << 63;
	for (int i = 1; i < n; ++i)
		lis[i] = INT64_MAX;

	for (int i = 0; i < n; i++) {
		int j = int(upper_bound(lis.begin(), lis.end(), numbers[i]) - lis.begin());
		if (lis[j - 1] < numbers[i] && numbers[i] < lis[j])
			lis[j] = numbers[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}
	return ans;
}

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] > tail[length - 1])
			tail[length++] = v[i];
		else {
			// TO check whether the element is not present before hand 
			auto it = find(tail.begin(), tail.begin() + length, v[i]);
			if (it != tail.begin() + length) {
				continue;
			}
			// If not present change the tail element to v[i] 
			it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
			*it = v[i];
		}
	}

	return length;
}