#pragma once
#include <string>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class IVisitor
{
public:
	virtual ~IVisitor(void);
	virtual std::string Visit(CCircle circle);
	virtual std::string Visit(CRectangle circle);
	virtual std::string Visit(CTriangle circle);
};
