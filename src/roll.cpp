//
#include "roll.h"

roll::roll(die& die1_ref, die& die2_ref) : die1(die1_ref), die2(die2_ref), rolled_value(0) {}

void roll::roll_dice() {
    rolled_value = die1.roll() + die2.roll(); // Roll each die and sum their values
}

int roll::roll_value() const {
    return rolled_value;
}
