//
#include "shooter.h"
#include <iostream>

roll* shooter::throw_dice(die& die1, die& die2) {
    roll* newroll = new roll(die1, die2); // Create a dynamic instance of Roll
    newroll->roll_dice(); // Call Roll's roll_dice method
    rolls.push_back(newroll); // Add the Roll instance to the vector
    return newroll; // Return the Roll instance
}

void shooter::display_rolled_values() {
    for (const auto& roll : rolls) {
        std::cout << "Rolled value: " << roll->roll_value() << std::endl;
    }
}

shooter::~shooter() {
    for (auto& roll : rolls) {
        delete roll; // Delete each dynamically allocated Roll object
    }
    rolls.clear(); // Clear the vector
}