#include "../include/TESTS.h"



    void Tests::testPlayer (){
    // PLAYER TEST
    char player1Choice = 'X';
    char player2Choice = '0';
    
    Player player1("Nicolas", player1Choice);
    Player player2("Marcelo", player2Choice);
    
    cout << "Player 1 afficher info: \n";
    player1.afficherInfo();
    cout << "\nPlayer 2 afficher info: \n";
    player2.afficherInfo();
    cout << "\nPlayer 1 get role: \n";
    cout << player1.getRole();
    }

    void Tests::testBoard ()
    {
    //BOARD TEST
    int size = 8;
    Board board(size);
    board.modifyBoard(4,4,'X');
    board.print();
    }