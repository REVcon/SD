#pragma once
#include "Shape.h"

class CCircle final : public CShape
{
public:
	CCircle(const Point& center, CLongNumber radius);
	~CCircle(void);
	virtual CLongNumber GetPerimeter();
	virtual CLongNumber GetSquare();
	void Accept(IVisitor&v);
private:
	CLongNumber m_radius;
	const CLongNumber PI = CLongNumber("31415926535");
	const CLongNumber RATIO = CLongNumber("10000000000");
};

