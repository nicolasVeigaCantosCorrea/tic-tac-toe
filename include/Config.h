#ifndef Config_H
#define Config_H

#include <iostream>

class Config
{
private:
    /* data */
    int m_mode;
    int m_boardSize;
public:
    //declarer fonctions
    Config();
    void setMode(int p_mode);
    void setBoardSize(int p_size);

    int getMode();
    int getBoardSize();
};

#endif
