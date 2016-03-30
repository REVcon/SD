#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class IVisitor
{
public:
	IVisitor(){};
	virtual ~IVisitor(void){};
	virtual void Visit(CCircle & shape) = 0;
	virtual void Visit(CRectangle & shape) = 0;
	virtual void Visit(CTriangle & shape) = 0;
};