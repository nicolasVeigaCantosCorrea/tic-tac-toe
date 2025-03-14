#include "../include/PLAYER.h"

#include <iostream>

Player::Player(const std::string& p_nom, const char& p_role)
: m_nom(p_nom), m_role(p_role)
{ }

bool Player::isX () const
{
    return m_role == 'X';
}

char Player::getRole () const
{
    return m_role;
}

void Player::afficherInfo () const
{
std::cout << "Nom: " << m_nom << "\n";
std::cout << "joueurId: " << getRole() << "\n";
}