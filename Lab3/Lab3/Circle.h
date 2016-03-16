#pragma once
#include "Shape.h"

class CCircle final : public CShape
{
public:
	CCircle(const Point& center, int radius);
	~CCircle(void);
	virtual double GetPerimeter();
	virtual double GetSquare();
private:
	int m_radius;
};

