#include "Navigation.h"

Navigation::Navigation(int x)
	: m_coord(x)
{
}

const int Navigation::GetCoord() const
{
	return this->m_coord;
}

void Navigation::SetCoord(int x)
{
	this->m_coord = x;
}

void Navigation::Render()
{
}

void Navigation::MoveLeft()
{
}

void Navigation::MoveRight()
{
}
