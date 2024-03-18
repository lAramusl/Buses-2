#include <iostream>
#include <set>

std::set <int> buses;

class Bus{
private:
  int bus_number;
  int travel_time;
  int A;
  int B;

public:
void add_bus(int a, int b) {
      A = a;
      B = b;
      std::cin >> bus_number;
      while( !(buses.find(bus_number) == buses.end()) ){
        std::cout << "Bus " << bus_number << " already exists." << "Сhoose another numberю" << std::endl;
        std::cin >> bus_number;
      }
      buses.insert(bus_number);
  
      travel_time = Floyd_Warshall(A, B);
     }

};

int main() {
  
}