#pragma once
#include "IFactory.h"
#include "Circle.h"
#include "Singleton.h"

class CircleFactory : public CFactory
{
public:
	std::shared_ptr<CShape> CreateShape(std::string &paramsStr)
	{
		CCircle circle(Parser::GetPoint(paramsStr), Parser::GetNumber(paramsStr));
		return std::make_shared<CCircle>(circle);
	}
};