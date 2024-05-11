//
#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h" // Include the Roll class header
#include <vector>

class shooter {
public:
    roll* throw_dice(die& die1, die& die2); // Method to simulate shooting dice with two Die objects
    void display_rolled_values(); // Method to iterate through the vector of Roll pointers and display roll values
    ~shooter(); // Destructor to free memory for dynamically allocated Roll objects

private:
    std::vector<roll*> rolls; // Vector to store dynamically allocated Roll objects
};

#endif