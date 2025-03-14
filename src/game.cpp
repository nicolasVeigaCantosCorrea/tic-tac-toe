#include "../include/GAME.h"

using std::cout;
using std::cin;


// if mode == 1 : PvP
// if mode == 2 : PvM (player vs machine)

void Game::gameMode(int &gameType)
{
    bool isValid = true;
    cout << "1) Player vs Player\n";
    cout << "2) Player vs Machine\n";
    do
    {
        isValid = true;
        cout << "Pick either 1 or 2 for your game mode: ";
        cin >> gameType;
        if (gameType != 1 && gameType != 2)
        {
            isValid = false;
            cout << " ** Please write a valid option (1 or 2) **\n";
        }
    } while (!isValid);
}