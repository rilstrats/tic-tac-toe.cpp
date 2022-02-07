#pragma once
#include<string>


class Board {
	// Stores the board array and contains the functions to display the board and check for winners or a tie.

public:
	Board() {}

	std::string squares[9] = { "0","1","2","3","4","5","6","7","8" };

	void display_board(); 

	bool win_check(std::string current_player);

	void display_winner(std::string current_player);

	void display_cat();

};

