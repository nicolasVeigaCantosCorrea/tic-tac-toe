#ifndef Config_H
#define Config_H

#include <iostream>

class Config
{
private:
    /* data */
    int m_mode = 2; // default = 2; PvM (contre machine)
    int m_boardSize = 3; // default = 3; 3x3
    bool m_isFirst = true;
public:
    //declarer fonctions
    void setMode(int p_mode);
    void setBoardSize(int p_size);
    void SetPlayingFirst(bool p_isFirst);

    int getMode() const;
    int getBoardSize() const;
    bool getPlayingFirst() const;
};

#endif
