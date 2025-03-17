#include "input/Menu.h"
#include "sstream"
using std::cout;
using std::cin;

Menu::Menu(Config& p_config)
    : config(p_config)
{
    cout << "\n====== Menu ======\n";
    chooseMode();
    cout << "\n";
    chooseSize();

}

// if mode == 1 : PvP
// if mode == 2 : PvM (player vs machine)

void Menu::chooseMode()
{
    cout << "1) Player vs Player\n";
    cout << "2) Player vs Machine\n\n";
    cout << "Pick either 1 or 2 for your game mode: ";

    while (true)
    {
        cin >> m_mode;
        if (m_mode == 1 || m_mode == 2) 
        {
            config.setMode(m_mode);
            break;
        }
        else
        {
            cout << " ** Please write a valid option (1 or 2) **\n\n";
            cout << "Game mode picked: ";
        }
    }
    if (m_mode == 2) 
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer 
        // Retirer cin.ignore une fois que tous les cin sont converti à std::getline.

        std::string input;
        while (true)
        {
            cout << "Do you wish to play first? (y/n): ";
            std::getline(cin, input);
            if (input == "n" || input == "y") break;
            cout << "Invalid input! \n";
        }
        input == "y" ? config.SetPlayingFirst(true) : config.SetPlayingFirst(false);
    }
}

void Menu::chooseSize()
{
    cout << "Choose board size (i.e. 3 for a 3x3 board)\n";
    cout << "Minimal size is 3\n";
    cout << "Board size picked: ";

    while (true)
    {
        cin >> m_boardSize;
        if (m_boardSize >= 3)
        {
            config.setBoardSize(m_boardSize);
            cout << std::endl;
            break;
        }
        else
        {
            cout << " ** Please write a valid size **\n";
            cout << "Board size picked: ";
        }
    }
}