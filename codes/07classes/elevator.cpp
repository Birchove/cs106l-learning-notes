// File: elevator.cpp

#include "elevator.h"
#include <iostream>

Elevator::Elevator(int capacity){
    if (capacity < 0){
        std::cerr << "Invalid capacity! \n";
        capacity = 1;
    }


    this -> capacity = capacity;
    floor = 0;
}

void Elevator::request(int floor){
    this -> floor = floor;
}
