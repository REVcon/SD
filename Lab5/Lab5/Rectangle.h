#pragma once
#include "Shape.h"

class CRectangle final : public CShape
{
public:

	CRectangle(const Point& first, const Point& second);
	~CRectangle(void);
	CLongNumber GetPerimeter();
	CLongNumber GetSquare();

private:
	CLongNumber m_firstSide;
	CLongNumber m_secondSide;
};

