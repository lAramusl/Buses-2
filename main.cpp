#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Bus.h"
#include "Rafik.h"
#include "Aram.h"
#include "floyd_warshall.h"




int main() {
    std::cout << "This program will help you design a transport network in your city and performs the following functions: " << std::endl << 
"1) Add_bus A B : the function adds a bus that has its own number , the bus travels from start point (A) to finish point (B) and will travel the minimum time it will take to cover this distance. " << std::endl <<
"2) Construct_street A B T: The function constructs a road between points A and B with , adding it to your city map and also records the time T it takes the bus to travel from A to B. Once the road is built, the shortest bus routes will be updated if neccessary. "  << std::endl <<
"3) Detalis | : shows the intersections that the bus passes from point A to point B" << std::endl <<   
"Enter any key to continue to program.";
    char start;
    std::cin >> start;
    std::size_t n = 0;
    std::size_t m = 0;
    std::cout << "To end the program enter exit" << std::endl;
    std::cout << "Enter the number of crossroads : ";
    std::cin >> n;
    std::cout << std::endl << "Enter the number of roads : ";
    std::cin >> m;
    
  
    std::vector<std::vector<std::pair<std::size_t, int>>> g(n, std::vector<std::pair<std::size_t, int>>());
    std::cout << "enter the numbers for crossroads A B and the time it takes the bus to travel this route" << std::endl;
      
    g = init_graph(n,m);

    std::vector<std::vector<int>> optimal_travel_times = floyd_warshall(g);
    std::cout << "Enter the functions you want to use :\n";


    std::vector<Bus> Buses;
    Buses.reserve(10);

    std::string function;

  while(true){

    std::cin >> function;

    if (function == "add_bus") {
        add_bus(Buses, optimal_travel_times);
    }

    else if (function == "construct_street") {
        construct_street(g, optimal_travel_times, Buses);
    }

    else if (function == "details") {
        details(g, Buses);
    }

    else if (function == "exit"){
        break;
    }

    else{
      std::cout << "Invalid operation" << std::endl;
    }
  }
  return 0;
}