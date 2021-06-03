#include <iostream>
#include <string>
#include <stdio.h>

void printGrid(char *grid);
bool check_win(char *grid);
//int cpu_move(char *grid); //to be implemented: a cpu to play against

int main() {

	char g[9] = {'m', 'n', 't', 's', 'd', 'a', 'e','q','y'};
	char *grid= g;
	std::string turn;

	std::cout << std::endl << "      WELCOME TO TICTACTOE GAME" << std::endl << std::endl;
	std::cout << std::endl << "   Enter grid number to place turn" << std::endl << std::endl;

	printGrid(grid);

	while(true) {

		std::cout << "Player 1 turn: " ;
		getline(std::cin, turn);
		std::cout << std::endl << std::endl;

		g[(stoi(turn)) - 1] = 'X';
		printGrid(grid);

		if(check_win(grid)) {
			std::cout << "Player 1 wins! Game over" << std::endl;
			break;
		}

		std::cout << "Player 2 turn: ";

		getline(std::cin, turn);

		g[(stoi(turn)) - 1] = 'O';
		std::cout << std::endl << std::endl;
		printGrid(grid);

		if(check_win(grid)) {
			std::cout << "Player 2 wins! Game over" << std::endl;
			break;
		}

	}

	return 0;
}


void printGrid(char *grid) {

	for (int i = 0; i < 9; ++i)
	{
		if(i == 3 || i == 6) {
			std::cout << std::endl;
			std::cout << "       -------|-------|-------" << std::endl;
		}
		std::cout << "        " ;

		if (grid[i] == 'X' || grid[i] == 'O')
		{
			std::cout << grid[i] << " " ;
		}
		 else std::cout << i + 1 << " " ;
	}

	std::cout << std::endl << std::endl;


	return;	
}

bool check_win(char *grid) {
	int i = 0;
		if(grid[i] == grid[i+1] && grid[i+1] == grid[i+2]) return true;
		if(grid[i] == grid[i+3] && grid[i+3] == grid[i+6]) return true;
		if(grid[i] == grid[i+4] && grid[i+4] == grid[i+8]) return true;
		if(grid[i + 1] == grid[i+4] && grid[i+4] == grid[i+7]) return true;
		if(grid[i + 2] == grid[i+4] && grid[i+4] == grid[i+6]) return true;
		if(grid[i + 3] == grid[i+4] && grid[i+4] == grid[i+5]) return true;
		if(grid[i + 6] == grid[i+7] && grid[i+7] == grid[i+8]) return true;
		
		else return false;

}



















