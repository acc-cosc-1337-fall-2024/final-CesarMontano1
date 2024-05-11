//
#include "die.h"

die::die() : sides(6) {} // Constructor to initialize sides to 6

int die::roll() {
    return rand() % sides + 1; // Generate a random number in the range 1 to sides
}