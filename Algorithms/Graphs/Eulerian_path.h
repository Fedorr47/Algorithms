#pragma once
#include <queue>
#include <vector>
#include <deque>
#include <stack>
#include <iostream> 
#include <string.h> 
#include <algorithm> 
#include <list> 

#include "graph_utils.h"
#include "DFS.h"

using namespace std;


void findEulerPath(
	vector<vector<unsigned>> graph_list, 
	deque<unsigned>& path_final,
	vector<unsigned>& answer,
	int vertex
)
{	
	auto start_vertex = vertex;
	deque<unsigned> path;
	path.push_back(vertex);
	path_final.push_back(vertex);
	vector<pair<unsigned, unsigned>> vizited;
	while (!path.empty())
	{
		auto vertex_current = path.front();
		auto v = graph_list[vertex_current][0];
		if (find(vizited.begin(), vizited.end(), 
			make_pair(
				std::min(vertex_current, v),
				std::max(vertex_current, v)
			)) != vizited.end())
		{
			if (vertex_current == start_vertex)
				return;
			graph_list[vertex_current].erase(graph_list[vertex_current].begin());
			path.pop_front();
			if (!graph_list[vertex_current].empty())
				path.push_front(graph_list[vertex_current][0]);
		}
		else
		{
			vizited.push_back(make_pair(
				std::min(vertex_current, v),
				std::max(vertex_current, v)));
			path.push_front(v);
			graph_list[vertex_current].erase(graph_list[vertex_current].begin());
			path_final.push_back(std::max(vertex_current, v));
		}
	}
}

bool is_euler(vector<vector<unsigned>> graph_list)
{
	auto vertex_current = graph_list.begin();
	auto end_vertexes = graph_list.end();
	for (int i = 0; vertex_current != end_vertexes; ++vertex_current, ++i)
	{
		if ((*vertex_current).size() % 2 != 0)
		{
			return false;
		}
	}
	return true;
}

void test_eulerian_path()
{
	vector<vector<unsigned>> graph_list;
	cin_vector(cin, graph_list);
	unsigned vertex_count = graph_list.size();
	deque<unsigned> path;
	vector<unsigned> answer;
	
	if (is_euler(graph_list))
	{
		findEulerPath(graph_list, path, answer, 0);
		for (auto i : path)
		{
			cout << i+1 << " ";
		}
	}
	else
	{
		cout << "NONE" << endl;
	}
}


  
