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

	// Start the game
	startMatch();
}

Game::~Game() 
{}

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
	int size = m_config.getBoardSize(); // Size de 0 à chiffre max.

	for (int ligne = 0; ligne < size; ligne++)
	{
		bool rowWin = true, colWin = true;

		for (int colonne = 0; colonne < size; colonne++)
		{
			if (m_board->getValue(colonne, ligne) != role) // check vertical line
			{
				rowWin = false;
			}

			if (m_board->getValue(ligne, colonne) != role) // Check for horizontal line
			{
				colWin = false;
			}
		}
		if (rowWin || colWin) return true;
	}

	bool mainDiagWin = true, antiDiagWin = true;
	for (int ligne = 0; ligne < size; ligne++)
	{
			if (m_board->getValue(ligne, ligne) != role) // Check for main diagonal line
			{
				mainDiagWin = false;
			}

			if (m_board->getValue(ligne, size - 1 - ligne) != role) // Check for the anti diagonal line
			{
				antiDiagWin = false;				
			}
		}
	return mainDiagWin || antiDiagWin;
}

bool Game::isFull() const
{
	int size = m_config.getBoardSize();

	for ( int ligne = 0; ligne < size; ligne++)
	{
		for ( int colonne = 0; colonne < size; colonne++)
		{
			if (m_board->getValue(ligne, colonne) == ' ') return false;
		}
	}
	return true;
}

void Game::restartMatch()
{
	std::string input;
	char choice;
	while (true)
	{
		cout << "Do you wish to play again? (y/n): ";
		std::getline(cin, input);
		std::stringstream ss(input);
		if (ss >> choice && (choice == 'n' || choice == 'y')) break;
		cout << "Invalid input! \n";
	}
	cout << "\n";
	if (choice == 'y') startMatch();
}

void Game::startMatch()
{
	bool isPlaying = true, isValid;
	int counter = 1;
	m_board = new Board(m_config.getBoardSize());

	cout << "\n====== Game ======\n";
	m_board->print();

	while (true) // One match
	{
		isValid = true; // Probably not the best place to have the getMove error handling
		char role = 'X';
		do
		{
			getMove();
			if (m_board->getValue(m_ligne - 1, m_colonne - 1) != ' ') // This is really weird, fix m_ligne to do a -1 before sending to board.
			{
				cout << "\nThere's already a value to that place! \n";
				isValid = false;
			}
		} while (!isValid);

		if (counter % 2 == 0) role = 'O';
		makeMove(role);
		m_board->print();
		counter++;

		if (checkWin(role))
		{
			cout << "The winner is : " << role << "\n\n";
			break;
		}
		if (isFull())
		{
			cout << "It's a tie!\n\n";
			break;
		}
	}
	delete m_board;	
	restartMatch();
}

