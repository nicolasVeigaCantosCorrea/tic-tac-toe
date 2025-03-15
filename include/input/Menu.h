#ifndef Menu_H
#define Menu_H

#include "Config.h"

#include <iostream>
#include <vector>

using std::cout;
using std::cin;

class Menu
{
private:
    /* data */
    int m_mode;
    int m_boardSize;
    Config config;
public:
    //declarer fonctions
    Menu(Config& p_config);
    void chooseMode();
    // Name, role , how many people, size of board
   // void chooseName(std::string& name);
    void chooseSize();
};

#endif
