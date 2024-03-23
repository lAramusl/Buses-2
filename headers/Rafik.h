#ifndef RAFIKH
#define RAFIKH
#include <vector>
#include <set>
#include "Bus.h"

//Made by Rafik

const int INF = 1e8;

std::vector<std::pair<std::size_t, int>> Dijkstra
(const std::vector<std::vector<std::pair<std::size_t, int>>>& g, int v);

void details(std::vector<std::vector<std::pair<std::size_t, int>>>& g, const std::vector<Bus>& Buses);
#endif