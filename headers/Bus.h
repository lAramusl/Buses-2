#ifndef BUSH
#define BUSH
#include <vector>


//Made by Rafik


class Bus {
private:
    int travel_time;
    int starting_point;
    int end_point;

public:
    Bus(int T, int S, int E) :travel_time(T), starting_point(S), end_point(E) {}

    int get_starting_point() const {
        return starting_point;
    }

    int get_end_point() const {
        return end_point;
    }

    int get_travel_time() const{
        return travel_time;
    }

    int& time(){
        return travel_time;
    }
};

//adds bus to existing system
void add_bus(std::vector<Bus>& bus_system, std::vector<std::vector<int>>& optimal_travel_times);

#endif

