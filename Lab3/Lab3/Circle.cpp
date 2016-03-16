#include "Circle.h"

CCircle::CCircle(const Point& center, int radius)
	: m_radius(radius)
{
}

CCircle::~CCircle(void)
{
}


double CCircle::GetPerimeter()
{
	return 2 * m_radius * M_PI;
}

double CCircle::GetSquare()
{
	return M_PI * pow(m_radius, 2);
}

