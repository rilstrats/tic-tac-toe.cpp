#include "Board.h"
#include <string>
#include <iostream>

using namespace std;

void Board::display_board() {
	// Displays the Tic Tac Toe board
	cout << endl;
	cout << " " << squares[0] << " | " << squares[1] << " | " << squares[2] << endl;
	cout << "--- --- ---" << endl;
	cout << " " << squares[3] << " | " << squares[4] << " | " << squares[5] << endl;
	cout << "--- --- ---" << endl;
	cout << " " << squares[6] << " | " << squares[7] << " | " << squares[8] << endl;
	cout << endl;
}

bool Board::win_check(std::string current_player) {
	// Check to see if the current player has won the game
	string player = current_player;

	// Horizontal win conditions
	if (squares[0] == player and squares[1] == player and squares[2] == player) { return true; }
	else if (squares[3] == player and squares[4] == player and squares[5] == player) { return true; }
	else if (squares[6] == player and squares[7] == player and squares[8] == player) { return true; }

	// Vertical win conditions
	else if (squares[0] == player and squares[3] == player and squares[6] == player) { return true; }
	else if (squares[1] == player and squares[4] == player and squares[7] == player) { return true; }
	else if (squares[2] == player and squares[5] == player and squares[8] == player) { return true; }

	// Diagonal win conditions
	else if (squares[0] == player and squares[4] == player and squares[8] == player) { return true; }
	else if (squares[2] == player and squares[4] == player and squares[6] == player) { return true; }

	// No win conditions
	else {
		return false;
	}
}

void Board::display_winner(std::string current_player) {
	// Displays the board and winner
	string player = current_player;
	display_board();
	cout << "Player " << player << " wins!" << endl;
}

void Board::display_cat() {
	// Displays the board and that there has been a tie
	display_board();
	cout << "Cat. No one wins.";
}
