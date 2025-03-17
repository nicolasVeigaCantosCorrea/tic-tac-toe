#ifndef Board_H
#define Board_H

#include <vector>

class Board
{
private:
    /* data */
    const int m_size; 
    std::vector<std::vector<char>> board;

public:
    //declarer fonctions
    Board (int p_size = 3); // Création du board
    void modifyBoard (const int ligne, const int colonne, const char role);    // Modification board
    char getValue(const int ligne, const int colonne) const; // return role à coord
    void print() const;    // Affichage board
    //void restartBoard(); // Pour restarter un game.
};

#endif
