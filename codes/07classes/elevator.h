// File: elevator.h

#pragma once

class Elevator {
private:
    // private member fields
    int floor;
    int capacity;
public:
    //constructor
    Elevator(int capacity);
    // Public member functions
    void request(int floor);

};