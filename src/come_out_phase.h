//
#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h" // Include the base Phase class header

class comeoutphase : public phase {
public:
    rolloutcome get_outcome(roll* roll) override; // Override the base class virtual function
};

#endif
