#pragma once
#include "Shape.h"

class CTriangle final : public CShape
{
public:
	CTriangle(const Point& first, const Point& second, const Point& third);
	~CTriangle(void);
	CLongNumber GetPerimeter();
	CLongNumber GetSquare();
	void Accept(IVisitor&v);

private:
	CLongNumber m_firstSide;
	CLongNumber m_secondSide;
	CLongNumber m_thirdSide;
};

