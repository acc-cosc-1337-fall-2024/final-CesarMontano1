//
#ifndef PHASE_H
#define PHASE_H

#include "roll.h" // Include the Roll class header
#include <iostream>

enum class rolloutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

class phase {
public:
    virtual rolloutcome get_outcome(roll* roll) = 0; // Pure virtual function to get the outcome based on a Roll

    // Virtual destructor to allow proper destruction of derived classes
    virtual ~phase() = default;
};

#endif
