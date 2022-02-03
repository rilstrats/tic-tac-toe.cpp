#include <iostream>
#include <string>
using namespace std;

class Player {
	// Determines which player's turn it is and has functions to have the player take their turn and 

public:
	Player() {}

	string current_player = "X";

	void take_turn(string squares[9]) {
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
			else if ( std::stoi(squares[choice]) == choice) {
				squares[choice] = current_player;
				return;
			}
		}
	}

	void switch_player() {
		// Switches to the next player
		if (current_player == "X") { current_player = "O"; }
		else if (current_player == "O") { current_player = "X"; }
	}

};

class Board {
	// Stores the board array and contains the functions to display the board and check for winners or a tie.

public:
	Board() {}

	string squares[9] = { "0","1","2","3","4","5","6","7","8" };

	void display_board() {
		// Displays the Tic Tac Toe board
		cout << endl;
		cout << " " << squares[0] << " | " << squares[1] << " | " << squares[2] << endl;
		cout << "--- --- ---" << endl;
		cout << " " << squares[3] << " | " << squares[4] << " | " << squares[5] << endl;
		cout << "--- --- ---" << endl;
		cout << " " << squares[6] << " | " << squares[7] << " | " << squares[8] << endl;
		cout << endl;
	}

	bool win_check(string current_player) {
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

	void display_winner(string current_player) {
		// Displays the board and winner
		string player = current_player;
		display_board();
		cout << "Player " << player << " wins!" << endl;
	}

	void display_cat() {
		// Displays the board and that there has been a tie
		display_board();
		cout << "Cat. No one wins.";
	}
};

int main() {
	// Runs the game
	cout << endl << "Please note, if you input anything besides an integer, you will crash the game." << endl;

	Player player;
	Board board;

	// Loops through 9 times and then displays that there is a tie
	for (int i = 0; i < 9; i++) {
		board.display_board();
		player.take_turn(board.squares);

		// If there is a winner it displays the winner and ends the game
		if (board.win_check(player.current_player)) {
			board.display_winner(player.current_player);
			return true;
		}

		player.switch_player();
	}

	board.display_cat();

}