#include "Rectangle.h"


CRectangle::CRectangle(const Point& first, const Point& second)
{
	m_firstSide = abs(first.x - second.x);
	m_secondSide = abs(first.y - second.y);
}

CRectangle::~CRectangle(void)
{
}

double CRectangle::GetPerimeter()
{
	return (m_firstSide + m_secondSide) * 2;
}

double CRectangle::GetSquare()
{
	return m_firstSide * m_secondSide;
}
