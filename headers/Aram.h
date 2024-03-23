#ifndef ARAMH
#define ARAMH
#include <vector>
#include "Bus.h"

//Made by Aram

//initializes graph as adjancency list
std::vector<std::vector<std::pair<std::size_t, int>>> init_graph(std::size_t n, std::size_t m);

//constructs street and re-calculates the optimal lengths
void construct_street
(
	std::vector<std::vector<std::pair<std::size_t, int>>>& graph,
	std::vector<std::vector<int>>& lenghts,
	std::vector<Bus>& buses
);

#endif
