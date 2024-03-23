#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include "floyd_warshall.h"

std::vector<std::vector<int>> floyd_warshall(std::vector<std::vector<std::pair<std::size_t, int>>> g)
{

	std::vector<std::vector<int>> street_lenghts(g.size(), std::vector<int>(g.size(), infinity));

	//initializing street_lenghts vector
	for (std::size_t i = 0; i < g.size(); ++i)
	{
		street_lenghts[i][i] = 0;
		for (std::size_t j = 0; j < g[i].size(); ++j)
		{
			std::size_t J = g[i][j].first;

			street_lenghts[i][J] = g[i][j].second;
			street_lenghts[J][i] = street_lenghts[i][J];
		}
	}

	//the floyd_warshall algorithm itself
	for (std::size_t k = 0; k < street_lenghts.size(); ++k)
	{
		for (std::size_t i = 0; i < street_lenghts.size(); ++i)
		{
			for (std::size_t j = 0; j < street_lenghts.front().size(); ++j)
			{
				if (street_lenghts[i][k] != infinity && street_lenghts[k][j] != infinity)
				{
					street_lenghts[i][j] = std::min(street_lenghts[i][j], street_lenghts[i][k] + street_lenghts[k][j]);
				}
			}
		}
	}

	return street_lenghts;
}