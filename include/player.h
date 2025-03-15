#ifndef Player_H
#define Player_H

#include <iostream>
class Player
{
private:
    /* data */
    const std::string m_nom;
    const char m_role; // 1 pour joueur 1 = X; 2 pour joueur 2 = O;
public:
    //declarer fonctions
    Player (const std::string& p_nom, const char& p_role);
    bool isX () const; // 0 pour O et 1 pour X
    char getRole() const;
    void afficherInfo () const;
};

#endif
