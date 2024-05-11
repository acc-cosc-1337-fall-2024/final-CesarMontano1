//
#ifndef dIE_H
#define dIE_H

#include <cstdlib> // For random number generation

class die {
public:
    die(); // Constructor
    int roll(); // Method to roll the die and return the result

private:
    int sides; // Number of sides on the die, initialized to 6
};

#endif