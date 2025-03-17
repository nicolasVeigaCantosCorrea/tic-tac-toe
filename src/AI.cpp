#include "AI.h"

#include <random>

void AI::setAllMoves(const Board& p_board, const int p_boardSize)
{
	m_allMoves.clear();

	for (int ligne = 0; ligne < p_boardSize; ligne++)
	{
		for (int colonne = 0; colonne < p_boardSize; colonne++)
		{
			if (p_board.getValue(ligne, colonne) == ' ')
			{
				m_allMoves.push_back({ ligne, colonne });
			}
		}
	}
}

std::vector<int> AI::chooseMove()
{
	std::random_device rd;  // Obtain a random seed
	std::mt19937 gen(rd()); // Mersenne Twister PRNG
	std::uniform_int_distribution<> distrib(0, m_allMoves.size() - 1); // Range of indices

	m_move = m_allMoves[distrib(gen)];

	return m_move;
}

std::vector<int> AI::getMove() const
{
	return m_move;
}