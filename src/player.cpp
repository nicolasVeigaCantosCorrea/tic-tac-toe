#include "Player.h"

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

void Player::setRole(char p_role)
{
    m_role = p_role;
}