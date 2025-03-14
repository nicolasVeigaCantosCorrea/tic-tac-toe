#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
class Board
{
private:
    /* data */
    const int m_size = 0; 
    std::vector<std::vector<char>> board;
public:
    //declarer fonctions
    Board (int& p_size); // Création du board
    void modifyBoard (int& ligne, int& colonne, const char& role);    // Modification board
    void print() const;    // Affichage board
};

#endif
