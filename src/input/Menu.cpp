#include "input/Menu.h"

Menu::Menu(Config& p_config)
    : config(p_config)
{
    chooseMode();
    cout << "\n";
    chooseSize();

}

// if mode == 1 : PvP
// if mode == 2 : PvM (player vs machine)

void Menu::chooseMode()
{
    cout << "1) Player vs Player\n";
    cout << "2) Player vs Machine\n";
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
            cout << " ** Please write a valid option (1 or 2) **\n";
            cout << "Game mode picked: ";
        }
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
            break;
        }
        else
        {
            cout << " ** Please write a valid size **\n";
            cout << "Board size picked: ";
        }
    }
}