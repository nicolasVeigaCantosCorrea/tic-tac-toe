#include "Game.h"

Game::Game(Player& p_player1, Player& p_player2, Config& p_config)
	:m_player1(p_player1), m_player2(p_player2), m_config(p_config), m_ligne(1), m_colonne(1)
{
	m_board = new Board(m_config.getBoardSize());
	startMatch();
}

Game::~Game() 
{
	delete m_board;
}

void Game::getMove() 
{
	cout << "Enter line and column with a space in between (e.g., 1 2): ";
	cin >> m_ligne >> m_colonne; // !!!!!!! Faire des erreurs pour ça plus tard !!!!!
}

void Game::makeMove(char role)
{
	m_board->modifyBoard(m_ligne, m_colonne, role);
}

//bool Game::checkWin()
//{
//	for (int ligne = 0; ligne < m_config.getBoardSize(); ligne++) { // check vertical line
//		for (int colonne = 0; colonne < m_config.getBoardSize(); colonne++) // Check horizontal line
//		{
//			if ();
//		}
//	}
//	return true
//}
void Game::startMatch()
{
	bool isPlaying = true;
	int counter = 1;
	while (isPlaying) {
		char role = 'X';
		m_board->print();
		getMove();
		if (counter % 2 == 0) { role = 'O'; }
		makeMove(role);
		counter++;
	}

}
