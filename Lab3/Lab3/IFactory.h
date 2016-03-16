#pragma once
#include "Shape.h"
#include <memory>

class IFactory
{
public:
	virtual std::shared_ptr<CShape> CreateShape(std::string &paramsStr) = 0;
protected:
	virtual ~IFactory(){}
	IFactory(){}
};


class CFactory : public IFactory
{
public:
	std::shared_ptr<CShape> CreateShape(std::string &paramsStr)
	{
		return nullptr;
	}
};
