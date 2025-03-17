#include "Game.h"

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;


Game::Game(Player& p_player1, Player& p_player2, Config& p_config)
	:m_player1(p_player1), m_player2(p_player2), m_config(p_config), m_ligne(1), m_colonne(1)
{
	// Clear the input buffer to avoid leftover newlines
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Initialize the board and start the game
	m_board = new Board(m_config.getBoardSize());
	cout << "\n====== Game ======\n";
	startMatch();
}

Game::~Game() 
{
	// maybe make print of winner/loser here. If the line below works.
	//cout << "\n==================\n";
	delete m_board;
}

void Game::getMove() 
{
	std::string input;
	while (true) 
	{
		std::cout << "Enter line and column separated by a comma (e.g., 1,2): ";
		std::getline(std::cin, input); // Read the entire input as a string

		std::stringstream ss(input);
		char comma;

		if (ss >> m_ligne >> comma >> m_colonne && comma == ',') {
			// Check if the coordinates are within the valid range
			if (m_ligne >= 1 && m_ligne <= m_config.getBoardSize() &&
				m_colonne >= 1 && m_colonne <= m_config.getBoardSize()) {
				break; // Valid input, exit the loop
			}
			else {
				std::cout << "Invalid coordinates! Please enter values between 1 and "
					<< m_config.getBoardSize() << ".\n";
			}
		}
		else {
			std::cout << "Invalid input! Please use the format 'line,column' (e.g., 1,2).\n";
		}

		// Clear the input buffer only if the input was invalid
		std::cin.clear();
	}
}

void Game::makeMove(char role)
{
	m_board->modifyBoard(m_ligne-1, m_colonne-1, role);
}

bool Game::checkWin(const char role) const
{
	int ligne = 0, colonne = 0, size = m_config.getBoardSize() - 1;; // Size de 0 à chiffre max.
	bool rowWin = true, colWin = true, mainDiagWin = true, antiDiagWin = true;

	for (ligne; ligne <= size; ligne++) 
	{ 
		for (colonne; colonne <= size; colonne++)
		{
			if (m_board->getValue(colonne, ligne) != role) // check vertical line
			{
				rowWin = false;
			}

			if (m_board->getValue(ligne, colonne) != role) // Check for horizontal line
			{
				colWin = false;
			}
			if (m_board->getValue(colonne, colonne) != role) // Check for main diagonal line
			{
				mainDiagWin = false;
			}

			if (m_board->getValue(size - colonne, colonne) != role) // Check for the anti diagonal line
			{
				antiDiagWin = false;				
			}
		}
	}
	return rowWin || colWin || mainDiagWin || antiDiagWin;
}

void Game::startMatch()
{
	bool isPlaying = true, isValid;
	int counter = 1;
	while (isPlaying) {
		isValid = true;
		char role = 'X';
		m_board->print();
		if (checkWin(role))
		{
			cout << "Le joueur gagnant est: " << role << "\n\n";
			break;
		}
		do
		{
			getMove();
			if (m_board->getValue(m_ligne-1, m_colonne-1) != ' ') // This is really weird, fix m_ligne to do a -1 before sending to board.
			{
				cout << "\nThere's already a value to that place! \n";
				isValid = false; 
			}
		} while (!isValid);

		if (counter % 2 == 0) { role = 'O';}
		makeMove(role);
		counter++;
		
	}

}
