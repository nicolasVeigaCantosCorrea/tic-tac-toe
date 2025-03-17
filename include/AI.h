#ifndef AI_H
#define AI_H

#include <iostream>
#include <vector>
#include "Board.h"

class AI
{
private:
    /* data */
    std::vector<std::vector<int>> m_allMoves;
    std::vector<int> m_move;

public:
    //declarer fonctions
    void setAllMoves(const Board& p_board, const int p_boardSize);
    std::vector<int> chooseMove();
    std::vector<int> getMove() const;
};

#endif