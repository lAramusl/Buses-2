#include <iostream>
#include "Rafik.h"
#include "Bus.h"

std::vector<std::pair<std::size_t, int>> Dijkstra
(const std::vector<std::vector<std::pair<std::size_t, int>>>& g, int v) {
    std::set<std::pair<std::size_t, int>> set;

    set.emplace(std::make_pair(v, 0));

    std::vector<std::pair<std::size_t, int>> path(g.size(), std::make_pair(-1, INF));
    while (!set.empty()) {
        auto top = *set.begin();
        set.erase(set.begin());
        int current_v = top.first;
        int distance = top.second;
        path[current_v].second = distance;

        for (int u = 0; u < g[current_v].size(); ++u) {
            if (path[g[current_v][u].first].second > (path[current_v].second + g[current_v][u].second)) {
                set.erase(std::make_pair(g[current_v][u].second, path[g[current_v][u].first].second));

                path[g[current_v][u].first].second = (path[current_v].second + g[current_v][u].second);

                path[g[current_v][u].first].first = current_v;

                set.emplace(std::make_pair(g[current_v][u].first, path[g[current_v][u].first].second));
            }
        }
    }
    return path;
}

void details(std::vector<std::vector<std::pair<std::size_t, int>>>& g,const std::vector<Bus>& Buses)
{
    int bus_number;

    std::cin >> bus_number;

    std::vector<std::pair<std::size_t, int>> path = Dijkstra(g, Buses[bus_number].get_end_point());
    std::cout << std::endl << "Bus path is : ";
    int current_v = Buses[bus_number].get_starting_point();
    while (current_v != Buses[bus_number].get_end_point()) {
        std::cout << current_v << "->";
        current_v = path[current_v].first;
    }
    std::cout << Buses[bus_number].get_end_point() << std::endl;
}