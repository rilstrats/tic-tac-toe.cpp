#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

void Player::take_turn(string squares[9]) {
	// Takes the player's input, validates it, and then is claimed by that player (input other than an integer will cause this function to crash)
	cout << "Player " << current_player << "'s turn" << endl;
	int choice;
	while (true) {
		cout << "Type a square number to take [0-8]: ";
		cin >> choice;
		cout << endl;

		// If they enter a number already chosen by a player it prints an error message and prompts for input again
		if (squares[choice] == "X" or squares[choice] == "O") {
			cout << "Please enter a number not taken by a player." << endl;
		}

		// If they enter a number out of range it prints an error message and prompts for input again
		else if (choice < 0 or choice > 8) {
			cout << "Please enter a valid number between 0 and 8." << endl;
		}

		// If the number is valid it will be claimed by the current_player (If anything other than an integer is input it will crash here)
		else if (std::stoi(squares[choice]) == choice) {
			squares[choice] = current_player;
			return;
		}
	}
}

void Player::switch_player() {
	// Switches to the next player
	if (current_player == "X") { current_player = "O"; }
	else if (current_player == "O") { current_player = "X"; }
}