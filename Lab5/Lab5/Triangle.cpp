#include "Triangle.h"
#include "IVisitior.h"


CTriangle::CTriangle(const Point& first, const Point& second, const Point& third)
{
	m_firstSide = Sqrt(Sqr(first.x - second.x) + Sqr(first.y - second.y));
	m_secondSide = Sqrt(Sqr(third.x - second.x) + Sqr(third.y - second.y));
	m_thirdSide = Sqrt(Sqr(third.x - first.x) + Sqr(third.y - first.y));
}

CTriangle::~CTriangle(void)
{
}


CLongNumber CTriangle::GetPerimeter()
{
	return m_firstSide + m_secondSide + m_thirdSide;
}

CLongNumber CTriangle::GetSquare()
{
	CLongNumber p = GetPerimeter() / 2;
	CLongNumber square = Sqrt(p * (p - m_firstSide) * (p - m_secondSide) * (p - m_thirdSide));
	return square;
}

void CTriangle::Accept(IVisitor&v)
{
	v.Visit(*this);
}
