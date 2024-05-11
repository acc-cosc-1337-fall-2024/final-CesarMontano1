//
#ifndef ROLL_H
#define ROLL_H

#include "die.h" // Include the Die class header

class roll {
public:
    roll(die& die1, die& die2); // Constructor taking references to two Die objects
    void roll_dice(); // Method to roll the dice
    int roll_value() const; // Method to return the rolled value

private:
    die& die1;
    die& die2;
    int rolled_value;
};

#endif
