#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"


using namespace std;


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