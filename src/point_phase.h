//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h" // Include the base Phase class header

class pointphase : public phase {
public:
    pointphase(int p); // Constructor to set the private variable point
    rolloutcome get_outcome(roll* roll) override; // Override the base class virtual function

private:
    int point; // Private variable to store the point value
};

#endif
