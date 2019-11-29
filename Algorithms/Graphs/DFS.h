#pragma once
#include <vector>

#include "graph_utils.h"
using namespace std;

int dfs(vector<int>& visited, vector<vector<unsigned>> vertexs, unsigned v)
{
	for (auto vertex : vertexs[v])
	{
		if (!visited[vertex])
		{
			visited[vertex] = 1;
			dfs(visited, vertexs, vertex);
		}
	}
	return 0;
}

void test_dfs()
{
	vector<vector<unsigned>> graph_list;

	cin_vector(cin, graph_list);
	unsigned vertex_count = graph_list.size();
	vector<int> visited(vertex_count, 0);
	unsigned connected_count = 0;
	for (unsigned v = 0; v < vertex_count; ++v)
	{
		if (!visited[v])
		{
			++connected_count;
			visited[v] = 1;
			dfs(visited, graph_list, v);
		}
	}
	cout << connected_count;
}