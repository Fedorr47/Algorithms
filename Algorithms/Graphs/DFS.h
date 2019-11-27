#include <vector>
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
	unsigned vertex_count, edges_count;
	
	cin >> vertex_count;
	cin >> edges_count;

	vector<vector<unsigned>> vertex_list(vertex_count);

	unsigned first = 0;
	unsigned second = 0;
	while (edges_count) {
		--edges_count;
		cin >> first;
		cin >> second;
		--first;
		--second;
		vertex_list[first].push_back(second);
		vertex_list[second].push_back(first);
	}
	vector<int> visited(vertex_count, 0);
	unsigned connected_count = 0;
	for (unsigned v = 0; v < vertex_count; ++v)
	{
		if (!visited[v])
		{
			++connected_count;
			visited[v] = 1;
			dfs(visited, vertex_list, v);
		}
	}
	cout << connected_count;
}