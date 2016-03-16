#pragma once
#include "Shape.h"
#include <memory>

class IFactory
{
public:
	virtual std::shared_ptr<CShape> CreateShape(std::string &paramsStr) = 0;
	virtual ~IFactory(){}
	IFactory(){}
};
