#pragma once
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <string>
#define _USE_MATH_DEFINES
#include "math.h"
#include <sstream>
#include "LongNumber\LongNumber.h"

class IVisitor;

class CShape
{
public:
	CShape(void);
	virtual ~CShape(void);
	virtual CLongNumber GetPerimeter() = 0;
	virtual CLongNumber GetSquare() = 0;
	virtual void Accept(IVisitor &v) = 0;
};


struct Point
{
	CLongNumber x;
	CLongNumber y;
};

namespace Parser
{
	Point GetPoint(std::string & arg);
	CLongNumber GetNumber(std::string & arg);
}