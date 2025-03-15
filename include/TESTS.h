#ifndef Tests_H
#define Tests_H

#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "input/Menu.h"
#include "Config.h"

#include <iostream>
using std::cout;
using std::cin;

class Tests
{
public:
    void testPlayer ();
    void testBoard ();
    void testMenu ();
};

#endif