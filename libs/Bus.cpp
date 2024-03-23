#include "Bus.h"
#include <algorithm>
#include <iostream>

void add_bus(std::vector<Bus>& bus_system, std::vector<std::vector<int>>& optimal_travel_times)
{
	int start_point;
	int finish_point;

	std::cin >> start_point >> finish_point;

	Bus bus(optimal_travel_times[start_point][finish_point], start_point, finish_point);

	bus_system.push_back(bus);
}