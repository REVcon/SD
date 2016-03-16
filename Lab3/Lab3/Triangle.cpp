#include "Triangle.h"


CTriangle::CTriangle(const Point& first, const Point& second, const Point& third)
{
	m_firstSide = sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
	m_secondSide = sqrt(pow(third.x - second.x, 2) + pow(third.y - second.y, 2));
	m_thirdSide = sqrt(pow(third.x - first.x, 2) + pow(third.y - first.y, 2));
}

CTriangle::~CTriangle(void)
{
}


double CTriangle::GetPerimeter()
{
	return m_firstSide + m_secondSide + m_thirdSide;
}

double CTriangle::GetSquare()
{
	double p = GetPerimeter() / 2;
	double square = sqrt(p * (p - m_firstSide) * (p - m_secondSide) * (p - m_thirdSide));
	return square;
}
