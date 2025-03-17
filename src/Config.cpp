#include "Config.h"

void Config::setMode(int p_mode) 
{
	m_mode = p_mode;
}

void Config::setBoardSize(int p_size)
{
	m_boardSize = p_size;
}

int Config::getMode() const
{
	return m_mode;
}

int Config::getBoardSize() const
{
	return m_boardSize;
}