#pragma once
#include "IFactory.h"
#include "Triangle.h"
#include "Singleton.h"

class TriangleFactory : public CFactory
{
public:
	std::shared_ptr<CShape> CreateShape(std::string &paramsStr)
	{
		CTriangle triangle(Parser::GetPoint(paramsStr), Parser::GetPoint(paramsStr), Parser::GetPoint(paramsStr));
		return std::make_shared<CTriangle>(triangle);
	}
};