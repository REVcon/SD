#include <stdio.h>
#include <tchar.h>
#include "LongNumber.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <memory>
#include <map>

using namespace std;

typedef function<CLongNumber(const CLongNumber &first,const  CLongNumber &second)> Handler;
typedef map<string, Handler> MathSignToHandle;

CLongNumber HandleAddition(const CLongNumber &first, const  CLongNumber &second)
{
	return first + second;
}

CLongNumber HandleSubtraction(const CLongNumber &first, const  CLongNumber &second)
{
	return first - second;
}

CLongNumber HandleMultiplication(const CLongNumber &first, const  CLongNumber &second)
{
	return first * second;
}

CLongNumber HandleDivision(const CLongNumber &first, const  CLongNumber &second)
{
	return first / second;
}


void HandleInput(const MathSignToHandle &handlers, istream& inpStrm, ostream& outStrm)
{
	std::string curMathExpression;
	while (getline(inpStrm, curMathExpression))
	{
		istringstream expresson(curMathExpression);
		string firstArg, secondArg, mathSign;
		if (expresson >> firstArg >> mathSign >> secondArg)
		{
			CLongNumber first(firstArg);
			CLongNumber second(secondArg);
			auto it = handlers.find(mathSign);
			if (it != handlers.cend())
			{
				try
				{
					auto result = it->second(first, second);
					outStrm << first.ToString() << ' ' + mathSign + ' ' << second.ToString() << " = " << result.ToString() << endl;
				}
				catch (const std::runtime_error &e)
				{
					outStrm << e.what() << endl;
				}			
			}
			else
			{
				outStrm << "Unknown math sign.\n";
			}

		}
		else
		{
			outStrm << "Invalid math expression.\n";
		}		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid parametrs, expected <input> <output> file" << endl;
		return 1;
	}
	MathSignToHandle handlers;
	handlers["+"] = HandleAddition;
	handlers["-"] = HandleSubtraction;
	handlers["*"] = HandleMultiplication;
	handlers["/"] = HandleDivision;
	ifstream inpStrm;
	inpStrm.open(argv[1]);
	ofstream outStrm;
	outStrm.open(argv[2]);
	HandleInput(handlers, inpStrm, outStrm);
	outStrm.close();

	return 0;
}