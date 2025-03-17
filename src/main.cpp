#include "Main.h"

int main()
{
    // HOME DEBUT
    home << "===== Tic-Tac-Toe =====\n"; 
    home << "1) Play\n";
    home << "2) Options\n";
    home << "3) Exit\n\n";
    home << "Pick 1 to play or 2 to config the game: ";
    // HOME FIN

    int choice; // Menu ou Play

    Config config;
    Player player1("1", 'X'); // For now let's have 2 players only
    Player player2("2", 'O'); // The goal is to have 2-4 players possibly
    Menu* menu = nullptr;
    Game* game = nullptr;

    bool isValid = false;
   
    while (true) 
    {
        std::cout << home.str();  // Probablement faire Class Home
        do
        {
            isValid = true;
            cin >> choice;

            switch (choice) {
            case 1: // Create Game
                game = new Game(player1, player2, config); 
                delete game;
                break;

            case 2: // Config game
                menu = new Menu(config); 
                delete menu;
                break;

            case 3: // Exit game
                return 0; 

            default: // If invalid choice
                std::cout << "Invalid choice!\n";
                cout << "Pick 1 to play or 2 to config the game: ";
                isValid = false;
                break;
            }
        } while (!isValid);
    }
}