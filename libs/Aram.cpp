#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include "floyd_warshall.h"
#include "Aram.h"

std::vector<std::vector<std::pair<std::size_t, int>>> init_graph(std::size_t n = 0, std::size_t m = 0)
{
	std::vector<std::vector<std::pair<std::size_t, int>>> g(n, std::vector<std::pair<std::size_t, int>>());

	for (std::size_t i = 0; i < m; ++i)
	{
		std::size_t u = 0;
		std::size_t v = 0;
		int k = 0;

		std::cin >> u >> v >> k;
		g[u].push_back(std::make_pair(v, k));
		g[v].push_back(std::make_pair(u, k));
	}

	return g;
}

//constructs street and re-calculates the optimal lengths
void construct_street
(
	std::vector<std::vector<std::pair<std::size_t, int>>>& graph,
	std::vector<std::vector<int>>& lenghts,
	std::vector<Bus>& buss
)
{
	std::size_t A = 0;
	std::size_t B = 0;
	std::size_t lenght = 0;

	std::cin >> A >> B >> lenght;

	if (A != B)
	{
		graph[A].emplace_back(B, lenght);
		graph[B].emplace_back(A, lenght);
	}

	lenghts = floyd_warshall(graph);

	for (std::size_t i = 0; i < buss.size(); ++i)
	{
		buss[i].time() = lenghts[buss[i].get_starting_point()][buss[i].get_end_point()];
	}
}