#include "Board.h"

Board::Board (int& p_size) 
: m_size(p_size), board(p_size, std::vector<char> (p_size,' '))
{}

void Board::modifyBoard (int& ligne, int& colonne, const char& role)
{
    if (ligne < m_size && colonne < m_size) // faite une classe pour gerer erreurs.
    {
        ligne -= 1;
        colonne -= 1;
        board[ligne][colonne] = role;
    }  
} 

void Board::print () const
{
    std::ostringstream intervalle; // print des petits traits entre lignes
    intervalle << " -";
    for (int i = 0; i < m_size; i++){
        intervalle << "----";
    }
    intervalle << "\n";
    
    cout << intervalle.str();
    for (int ligne = 0; ligne < m_size; ligne++) // À chaque ligne
    { 
        cout << ligne + 1;
        for (int colonne = 0; colonne < m_size; colonne++) // À chaque colonne
        {
            cout << "| " << board[ligne][colonne] << " ";
        }
        cout << "|\n";
        cout << intervalle.str();
    }

    std::ostringstream colonnes; // print des colonnes
    colonnes << "  ";
    for (int i = 0; i < m_size; i++)
    {
        colonnes << " " << i + 1 << "  ";
    }
    colonnes << std::endl;
    cout << colonnes.str();
}
