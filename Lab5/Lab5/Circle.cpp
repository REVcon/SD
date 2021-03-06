#include "Circle.h"
#include "IVisitior.h"

CCircle::CCircle(const Point& center, CLongNumber radius)
	: m_radius(radius)
{
}

CCircle::~CCircle(void)
{
}


CLongNumber CCircle::GetPerimeter()
{
	return m_radius * 2 * PI / RATIO;
}

CLongNumber CCircle::GetSquare()
{
	return Sqr(m_radius) * PI / RATIO;
}

void CCircle::Accept(IVisitor&v)
{
	v.Visit(*this);
}
