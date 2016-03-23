#pragma once
#include "IFactory.h"
#include "Circle.h"
#include "Singleton.h"

class CircleFactory : public CFactory
{
public:
	std::shared_ptr<CShape> CreateShape(std::string &paramsStr)
	{
		Point centre = Parser::GetPoint(paramsStr);
		CLongNumber rad = Parser::GetNumber(paramsStr);
		CCircle circle(centre, rad);
		return std::make_shared<CCircle>(circle);
	}
};