#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("die rolls return values between 1 and 6", "[Die]") {
    die die;

    for (int i = 0; i < 10; ++i) {
        int result = die.roll();
        REQUIRE(result >= 1);
        REQUIRE(result <= 6);
    }
}

TEST_CASE("Rolling two dice returns values between 2 and 12", "[Roll]") {
    die die1, die2;
    roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int result = roll.roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}