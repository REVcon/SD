#pragma once
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <string>
#define _USE_MATH_DEFINES
#include "math.h"
#include <sstream>

class CShape
{
public:
	CShape(void);

	virtual ~CShape(void);

	virtual double GetPerimeter() = 0;

	virtual double GetSquare() = 0;

};

struct Point
{
	int x;
	int y;
};

namespace Parser
{
	Point GetPoint(std::string & arg);
	int GetNumber(std::string & arg);
}