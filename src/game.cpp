#include "Game.h"

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;


Game::Game(Player& p_player1, Player& p_player2, Config& p_config)
	:m_player1(p_player1), m_player2(p_player2), m_config(p_config), m_ligne(1), m_colonne(1)
{
	m_board = new Board(m_config.getBoardSize());
	cout << "\n====== Game ======\n";
	startMatch();
}

Game::~Game() 
{
	// maybe make print of winner/loser here. If the line below works.
	cout << "\n==================\n";
	delete m_board;
}

void Game::getMove() 
{
	std::string input;
	while (true) 
	{
		cout << "Enter line and column separated by a comma (e.g., 1,2): ";

		std::getline(std::cin, input);
		std::stringstream ss(input);
		char comma;

		if (ss >> m_ligne >> comma >> m_colonne && comma == ',')
		{
			if (m_ligne >= 1 && m_ligne <= m_config.getBoardSize() &&
				m_colonne >= 1 && m_colonne <= m_config.getBoardSize())
			{
				break; // Valid input, exit the loop
			}
			else
			{
				std::cout << "Invalid coordinates! Please enter values between 1 and "
					<< m_config.getBoardSize() << ".\n";

			}
		}

		else 
		{
			std::cout << "Invalid input! Please use the format 'line,column' (e.g., 1,2).\n";
		}
		std::cin.clear();
	}
}

void Game::makeMove(char role)
{
	m_board->modifyBoard(m_ligne-1, m_colonne-1, role);
}

bool Game::checkWin()
{
	int ligne = 0;
	int colonne = 0;
	int size = m_config.getBoardSize() - 1; // Size de 0 à chiffre max.

	for (ligne; ligne <= size; ligne++) { // check vertical line

		for (colonne; colonne <= size; colonne++)
		{
			if (m_board->getValue(ligne, colonne) != m_board->getValue(ligne, size - colonne)) // Check for horizontal line
			{
			}
		}
	}
	return true;
}

void Game::startMatch()
{
	bool isPlaying = true;
	int counter = 1;
	while (isPlaying) {
		char role = 'X';
		m_board->print();
		cout << m_config.getBoardSize();
		getMove();
		if (counter % 2 == 0) { role = 'O'; }
		makeMove(role);
		counter++;
	}

}
