#pragma once
#include "Shape.h"

class CRectangle final : public CShape
{
public:

	CRectangle(const Point& first, const Point& second);
	~CRectangle(void);
	double GetPerimeter();
	double GetSquare();

private:
	double m_firstSide;
	double m_secondSide;
};

