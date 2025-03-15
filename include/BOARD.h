#ifndef Board_H
#define Board_H

#include <iostream>
#include <vector>
#include <sstream>

using std::cout;

class Board
{
private:
    /* data */
    const int m_size = 0; 
    std::vector<std::vector<char>> board;
public:
    //declarer fonctions
    Board (int p_size); // Création du board
    void modifyBoard (int& ligne, int& colonne, const char& role);    // Modification board
    char getValue(int& ligne, int& colonne) const; // return role à coord
    void print() const;    // Affichage board
};

#endif
