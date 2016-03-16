#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "IFactory.h"
#include "TriangleFactory.h"
#include "CircleFactory.h"
#include "RectangleFactory.h"
#include "Singleton.h"

using namespace std;

typedef function<shared_ptr<CShape>(string &paramsStr)> Handler;
typedef map<string, Handler> StringToHadlerMap;


shared_ptr<CShape> HandleCircle(string &paramsStr)
{
	return Singleton<CircleFactory>::GetInstance()->CreateShape(paramsStr);
}

shared_ptr<CShape> HandleRectangle(string &paramsStr)
{
	return Singleton<RectangleFactory>::GetInstance()->CreateShape(paramsStr);
}

shared_ptr<CShape> HandleTriangle(string &paramsStr)
{
	return Singleton<TriangleFactory>::GetInstance()->CreateShape(paramsStr);
}

void HandleInput(const StringToHadlerMap &handlers, istream& inpStrm, ostream& outStrm)
{
	string shapeType;
	while (inpStrm >> shapeType)
	{
		auto it = handlers.find(shapeType);
		string params;
		getline(inpStrm, params);
		if (it != handlers.cend())
		{
			try
			{
				auto res = it->second(params);
				outStrm << shapeType << " P=" << res->GetPerimeter() << "; S=" << res->GetSquare() << endl;
			}
			catch (const std::invalid_argument &e)
			{
				outStrm << e.what() << endl;
			}
		}
		else
		{
			outStrm << "Unknown shape type: " << shapeType << endl;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	StringToHadlerMap handlers;

	handlers["CIRCLE:"] = HandleCircle;
	handlers["RECTANGLE:"] = HandleRectangle;
	handlers["TRIANGLE:"] = HandleTriangle;

	if (argc != 3)
	{
		cout << "Invalid parametrs, expected <input> <output> file" << endl;
	}
	ifstream inpStrm;
	inpStrm.open(argv[1]);
	ofstream outStrm;
	outStrm.open(argv[2]);
	HandleInput(handlers, inpStrm, outStrm);
	outStrm.close();
	return 0;
}