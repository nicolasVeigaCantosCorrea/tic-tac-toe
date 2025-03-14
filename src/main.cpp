#include "../include/MAIN.h"

#include <iostream>

using std::cout;
using std::cin;

int main()
{
    char player1Choice = 'X';
    char player2Choice = '0';
    
    Player player1("Nicolas", player1Choice);
    Player player2("Marcelo", player2Choice);
    
    cout << "\tPlayer 1: \n";
    player1.afficherInfo();
    cout << "\tPlayer 2: \n";
    player2.afficherInfo();
    cout << player1.getRole();


    return 0;
}