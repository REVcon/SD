#include "Rectangle.h"
#include "IVisitior.h"


CRectangle::CRectangle(const Point& first, const Point& second)
{
	m_firstSide = first.x - second.x;
	m_secondSide = first.y - second.y;
}

CRectangle::~CRectangle(void)
{
}

CLongNumber CRectangle::GetPerimeter()
{
	return (m_firstSide + m_secondSide) * 2;
}

CLongNumber CRectangle::GetSquare()
{
	return m_firstSide * m_secondSide;
}

void CRectangle::Accept(IVisitor&v)
{ 
	v.Visit(*this); 
}