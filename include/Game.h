#ifndef Game_H
#define Game_H

#include "Board.h"
#include "Player.h"
#include "Config.h"
#include "AI.h"

class Game
{
private:
    /* data */
    int m_ligne, m_colonne;
    const Player& m_player1;
    const Player& m_player2;
    const Config& m_config;
    AI m_robot;
    std::unique_ptr<Board> m_board;
public:
    //declarer fonctions

    Game(Player& p_player1, Player& p_player2, Config& p_config);

    Game(const Game&) = delete; // Disable copy constructor
    Game& operator=(const Game&) = delete; // Disable assignment operator

    void getMove();
    void makeMove(char role);
    bool checkWin(const char role) const;
    bool isFull() const; // checks for draw.
    void startMatch();
    
    void restartMatch(); // Fonction pour savoir si joeur veux continuer de jouer.
};

#endif
