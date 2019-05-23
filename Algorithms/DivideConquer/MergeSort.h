#pragma once
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>

std::deque<int64_t> merge(std::deque<int64_t>&& left_mas, std::deque<int64_t>&& right_mas)
{
	std::deque<int64_t> merge_mas;
	while (!left_mas.empty() || !right_mas.empty())
	{
		if (left_mas.empty())
		{
			merge_mas.insert(merge_mas.end(), right_mas.begin(), right_mas.end());
			right_mas.clear();
			break;
		}
		else if (right_mas.empty())
		{
			merge_mas.insert(merge_mas.end(), left_mas.begin(), left_mas.end());
			left_mas.clear();
			break;
		}
		if (left_mas.front() < right_mas.front())
		{
			merge_mas.push_back(left_mas.front());
			left_mas.pop_front();
		}
		else if (left_mas.front() > right_mas.front())
		{
			merge_mas.push_back(right_mas.front());
			right_mas.pop_front();
		}
	}
	return merge_mas;
}

std::deque<int64_t> get_front(std::deque<std::deque<int64_t>>& deque_)
{
	std::deque<int64_t> vec_front;
	vec_front = deque_.front();
	deque_.pop_front();
	return std::move(vec_front);
}

void iterative_merge_sort(std::vector<int64_t>& massive)
{
	std::deque<std::deque<int64_t>> dq_mas;
	size_t size = massive.size();
	for (uint64_t i = 0; i < size; )
	{
		std::deque<int64_t> dq_part;
		if (i + 1 == size)
		{
			dq_part.push_back(massive[i]);
			dq_mas.push_back(std::move(dq_part));
			break;
		}
		else
		{
			dq_part.push_back(massive[i]);
			dq_part.push_back(massive[i + 1]);
			if (massive[i] > massive[i + 1])
			{
				std::swap(dq_part[0], dq_part[1]);
			}
			i += 2;
		}
		dq_mas.push_back(std::move(dq_part));
	}
	while (dq_mas.size() > 1)
	{
		std::deque<int64_t> right = get_front(dq_mas);
		std::deque<int64_t> left = get_front(dq_mas);
		dq_mas.push_back(merge(std::move(right), std::move(left)));
	}
	auto final_dequeu = get_front(dq_mas);
	massive = std::vector<int64_t>(final_dequeu.begin(), final_dequeu.end());
}