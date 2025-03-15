#include "Main.h"

int main()
{
    bool isValid = true;
    cout << "1) Play\n";
    cout << "2) Options\n";
    cout << "Pick 1 to play or 2 to config the game: ";
    
    Config config;
    Player* player1 = nullptr; // Declare pointers to Player objects
    Player* player2 = nullptr;
    Game* game = nullptr;

    do
    {
        isValid = true;
        cin >> choice;

        switch (choice) {
        case 1:
            player1 = new Player("1", 'X'); // Create Player 1
            player2 = new Player("AI", 'O'); // Create Player 2
            game = new Game(); // Create Game
            break;

        case 2:
            Menu menu(config);
            game = new Game(); // Create Game
            break;

        default:
            std::cout << "Invalid choice!\n";
            isValid = false;
            break;
        }
    } while (!isValid);

    //Tests tests;
    ////tests.testBoard();
    //tests.testMenu();
    return 0;
}