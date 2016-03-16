#pragma once
# include "Shape.h"

class CTriangle final : public CShape
{
public:
	CTriangle(const Point& first, const Point& second, const Point& third);
	~CTriangle(void);
	double GetPerimeter();
	double GetSquare();

private:
	double m_firstSide;
	double m_secondSide;
	double m_thirdSide;
};

