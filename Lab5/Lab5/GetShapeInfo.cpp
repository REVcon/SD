#include "GetShapeInfo.h"


void CGetShapeInfo::Visit(CCircle& shape)
{
	m_val = "CIRCLE: P=" + shape.GetPerimeter().ToString() + "; S=" + shape.GetSquare().ToString();
}


void CGetShapeInfo::Visit(CRectangle& shape)
{
	m_val = "RECTANGLE: P=" + shape.GetPerimeter().ToString() + "; S=" + shape.GetSquare().ToString();
}


void CGetShapeInfo::Visit(CTriangle& shape)
{
	m_val = "TRIANGLE: P=" + shape.GetPerimeter().ToString() + "; S=" + shape.GetSquare().ToString();
}

std::string CGetShapeInfo::GetValue()
{
	return m_val;
}


