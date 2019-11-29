#pragma once
#include <queue>
#include <vector>

#include "graph_utils.h"

using namespace std;

vector<int> bfs(vector<int>& visited, vector<vector<unsigned>> vertexs)
{
	queue<int> bfs_queue;
	bfs_queue.push(0);
	vector<int> mark(vertexs.size(),0);
	int level = 1;
	visited[0] = 1;
	while (!bfs_queue.empty())
	{
		if (visited[bfs_queue.front()] == 1)
		{
			auto current_vertex = bfs_queue.front();
			bfs_queue.pop();
			visited[current_vertex] = 2;
			for (auto vertex : vertexs[current_vertex])
			{
				if (visited[vertex] != 0)
					continue;
				visited[vertex] = 1;
				bfs_queue.push(vertex);
				mark[vertex] = mark[current_vertex] + 1;
			}
		}
	}
	return mark;
}

void test_bfs()
{
	vector<vector<unsigned>> graph_list;
	cin_vector(cin, graph_list);
	unsigned vertex_count = graph_list.size();
	vector<int> visited(vertex_count, 0);
    auto marks = bfs(visited, graph_list);
	copy(marks.begin(), marks.end(), std::ostream_iterator<int>(cout, " "));
}