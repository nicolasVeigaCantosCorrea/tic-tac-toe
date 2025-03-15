#ifndef Config_H
#define Config_H

#include <iostream>

class Config
{
private:
    /* data */
    int m_mode; // default = 1; PvP
    int m_boardSize; // default = 3; 3x3
public:
    //declarer fonctions
    Config();
    void setMode(int p_mode);
    void setBoardSize(int p_size);

    int getMode() const;
    int getBoardSize() const;
};

#endif
