#ifndef FLOYD_WARSHALLH
#define FLOYD_WARSHALLH
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>

//Made by Aram

constexpr int infinity = INT_MAX;

std::vector<std::vector<int>> floyd_warshall(std::vector<std::vector<std::pair<std::size_t, int>>> g);

#endif
