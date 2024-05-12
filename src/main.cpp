#include <iostream>
#include <cstdlib> // For srand and rand
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"


int main() 
{
	srand(static_cast<unsigned int>(time(0))); // seed for true random numbers

    die die1, die2; // Use correct capitalization for class names
    shooter shooter;
    roll* currentroll = shooter.throw_dice(die1, die2); // Use distinct name for roll variable
    if (!currentroll) {
        std::cerr << "error: unable to allocate memory for initial roll." << std::endl;
        return 1; // exit with error code
    }

    int rolledvalue = currentroll->roll_value();

    comeoutphase comeoutphase;
    while (comeoutphase.get_outcome(currentroll) == rolloutcome::natural || comeoutphase.get_outcome(currentroll) == rolloutcome::craps) {
        std::cout << "rolled " << rolledvalue << " - roll again" << std::endl;
        delete currentroll;
        currentroll = shooter.throw_dice(die1, die2);
        if (!currentroll) {
            std::cerr << "error: unable to allocate memory for roll during come out phase." << std::endl;
            return 1; // exit with error code
        }
        rolledvalue = currentroll->roll_value();
    }

    std::cout << "rolled " << rolledvalue << " - start of point phase" << std::endl;
    std::cout << "roll until " << rolledvalue << " or a 7 is rolled" << std::endl;

    int point = rolledvalue;
    delete currentroll;
    currentroll = shooter.throw_dice(die1, die2);
    if (!currentroll) {
        std::cerr << "error: unable to allocate memory for roll during point phase." << std::endl;
        return 1; // exit with error code
    }

    pointphase pointphase(point);
    while (pointphase.get_outcome(currentroll) != rolloutcome::seven_out && pointphase.get_outcome(currentroll) != rolloutcome::nopoint) {
        std::cout << "rolled " << currentroll->roll_value() << " - roll again" << std::endl;
        delete currentroll;
        currentroll = shooter.throw_dice(die1, die2);
        if (!currentroll) {
            std::cerr << "error: unable to allocate memory for roll during point phase." << std::endl;
            return 1; // exit with error code
        }
    }

    std::cout << "rolled " << currentroll->roll_value() << " - end of point phase" << std::endl;
    std::cout << "shooter rolled values:" << std::endl;
    shooter.display_rolled_values();

    delete currentroll; // free memory for final roll

	return 0;
}