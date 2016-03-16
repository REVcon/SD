#pragma once
#include "IFactory.h"
#include "Rectangle.h"

class RectangleFactory : IFactory
{
public:

	std::shared_ptr<CShape> CreateShape(std::string &paramsStr)
	{
		CRectangle rectangle(Parser::GetPoint(paramsStr), Parser::GetPoint(paramsStr));
		return std::make_shared<CRectangle>(rectangle);
	}
};