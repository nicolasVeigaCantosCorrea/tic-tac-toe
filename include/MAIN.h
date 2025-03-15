#ifndef Main_H
#define Main_H

#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "input/Menu.h"
#include "Config.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::cin;

std::ostringstream home;
int choice;

Config config;
Player* player1 = nullptr; // Declare pointers to Player objects
Player* player2 = nullptr;
Menu* menu = nullptr;
Game* game = nullptr;

#endif
