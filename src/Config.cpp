#include "Config.h"

void Config::setMode(int p_mode) 
{
	m_mode = p_mode;
}

void Config::setBoardSize(int p_size)
{
	m_boardSize = p_size;
}

void Config::SetPlayingFirst(bool p_isFirst)
{
	m_isFirst = p_isFirst;
}

int Config::getMode() const
{
	return m_mode;
}

int Config::getBoardSize() const
{
	return m_boardSize;
}

bool Config::getPlayingFirst() const
{
	return m_isFirst;
}