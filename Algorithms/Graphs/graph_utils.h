#pragma once

#include <iosfwd>
#include <istream>
#include <vector>

template<typename C = char, typename T = char_traits<C>, typename I = int>
bool cin_vector(std::basic_istream<C, T>& stream, std::vector<std::vector<I>>& graph)
{
	unsigned vertex_count, edges_count;
	stream >> vertex_count;
	stream >> edges_count;

	unsigned first, second;
	graph.resize(vertex_count);
	for (unsigned i = 0; i < edges_count; ++i)
	{
		stream >> first;
		stream >> second;
		--first;
		--second;
		graph[first].push_back(second);
		graph[second].push_back(first);
		sort(graph[first].begin(), graph[first].end());
		sort(graph[second].begin(), graph[second].end());
	}
	return true;
}