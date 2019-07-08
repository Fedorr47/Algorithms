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
		for (int j = 1; j < i-1; j++)
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
	int j = ans;
	while (k > 0)
	{
		(*ans_arr)[j] = k;
		j -= 1;
		k = prev_[k];
	}
	delete[] prev_;
	delete[] lis;
	return ans;
}