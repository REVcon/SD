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
		res.x = std::stoi(firstNum);
		res.y = std::stoi(secondNum);
	}
	catch (const std::invalid_argument)
	{
		throw std::invalid_argument("Invalid parametrs for creating");
	}
	return res;
}

int Parser::GetNumber(std::string & arg)
{
	size_t beginIndex = arg.find("=");
	std::istringstream iss(arg.substr(beginIndex + 1));

	std::string number;
	std::getline(iss, number);
	int res;
	try
	{
		res = std::stoi(number);
	}
	catch (const std::invalid_argument)
	{
		throw std::invalid_argument("Invalid parametrs for creating");
	}

	return res;
}
