//
#include "come_out_phase.h"

rolloutcome comeoutphase::get_outcome(roll* roll) {
    int rolledvalue = roll->roll_value(); // Get the rolled value from the Roll object

    if (rolledvalue == 7 || rolledvalue == 11) {
        return rolloutcome::natural;
    } else if (rolledvalue == 2 || rolledvalue == 3 || rolledvalue == 12) {
        return rolloutcome::craps;
    } else {
        return rolloutcome::point;
    }
}
