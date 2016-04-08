#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <functional>
#include <map>
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

void HandleInput(istream& inpStrm, ostream& outStrm)
{
	std::map<string, shared_ptr<CFactory>> handlers;
	handlers["CIRCLE:"] = Singleton<CircleFactory>::GetInstance();
	handlers["RECTANGLE:"] = Singleton<RectangleFactory>::GetInstance();
	handlers["TRIANGLE:"] = Singleton<TriangleFactory>::GetInstance();
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
				auto res = it->second->CreateShape(params);
				outStrm << shapeType << " P=" << res->GetPerimeter().ToString() << "; S=" << res->GetSquare().ToString() << endl;
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
	Singleton<CircleFactory>::destroy();
	Singleton<RectangleFactory>::destroy();
	Singleton<TriangleFactory>::destroy();	
}


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid parametrs, expected <input> <output> file" << endl;
	}
	ifstream inpStrm;
	inpStrm.open(argv[1]);
	ofstream outStrm;
	outStrm.open(argv[2]);
	HandleInput(inpStrm, outStrm);
	outStrm.close();
	return 0;
}