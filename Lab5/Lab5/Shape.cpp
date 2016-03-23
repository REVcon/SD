#include "Shape.h"


CShape::CShape()
{
}


CShape::~CShape()
{
}


Point Parser::GetPoint(std::string & arg)
{
	size_t beginIndex = arg.find("=");
	size_t endIndex = arg.find(";");

	std::istringstream iss(arg.substr(beginIndex + 1, endIndex));

	std::string firstNum, secondNum;
	std::getline(iss, firstNum, ',');
	std::getline(iss, secondNum, ';');

	arg = arg.substr(endIndex + 1);

	Point res;
	try
	{
		res.x = CLongNumber(firstNum);
		res.y = CLongNumber(secondNum);
	}
	catch (const std::invalid_argument)
	{
		throw std::invalid_argument("Invalid parametrs for creating");
	}
	return res;
}

CLongNumber Parser::GetNumber(std::string & arg)
{
	size_t beginIndex = arg.find("=");
	std::istringstream iss(arg.substr(beginIndex + 1));

	std::string number;
	std::getline(iss, number);
	CLongNumber res;
	try
	{
		res = CLongNumber(number);
	}
	catch (const std::invalid_argument)
	{
		throw std::invalid_argument("Invalid parametrs for creating");
	}

	return res;
}
