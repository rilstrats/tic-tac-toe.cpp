#pragma once
#include <string>

class Player {
	// Determines which player's turn it is and has functions to have the player take their turn and 

public:
	Player() {}

	std::string current_player = "X";

	void take_turn(std::string squares[9]);

	void switch_player();

};