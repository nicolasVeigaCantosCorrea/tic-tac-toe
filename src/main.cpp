#include "Main.h"

int main()
{
    bool isValid = true;
    home << "===== Tic-Tac-Toe =====\n";
    home << "1) Play\n";
    home << "2) Options\n";
    home << "3) Exit\n\n";
    home << "Pick 1 to play or 2 to config the game: ";

    std::cout << home.str();
    do
    {
        isValid = true;
        cin >> choice;

        switch (choice) {
        case 1:
            player1 = new Player("1", 'X'); // Create Player 1 // Probably create Players outside of loop. Make it possible to modify name with menu.
            player2 = new Player("AI", 'O'); // Create Player 2
            game = new Game(*player1, *player2, config); // Create Game
            break;

        case 2:
            menu = new Menu(config);
            game = new Game(*player1, *player2, config); // Create Game
            break;
        case 3:
            return 0;

        default:
            std::cout << "Invalid choice!\n";
            isValid = false;
            cout << "Pick 1 to play or 2 to config the game: ";
            break;
        }
    } while (!isValid);
    delete player1;
    delete player2;
    delete menu;
    delete game;
    return 0;
}