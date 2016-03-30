#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "IVisitior.h"

class CGetShapeInfo : public IVisitor
{
public:
	void Visit(CCircle & shape);
	void Visit(CRectangle &shape);
	void Visit(CTriangle &shape);
	std::string GetValue();
private:
	std::string m_val;
};

