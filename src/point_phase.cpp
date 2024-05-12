//
#include "point_phase.h"

pointphase::pointphase(int p) : point(p) {} // Constructor to set the point value

rolloutcome pointphase::get_outcome(roll* roll) {
    int rolledvalue = roll->roll_value(); // Get the rolled value from the Roll object

    if (rolledvalue == point) {
        return rolloutcome::point;
    } else if (rolledvalue == 7) {
        return rolloutcome::seven_out;
    } else {
        return rolloutcome::nopoint;
    }
}
