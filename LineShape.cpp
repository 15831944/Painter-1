#include "stdafx.h"
#include "LineShape.h"


int CLineShape::PythagorenTheorem(CPoint point_1,CPoint point_2) {
	return sqrt((startPoint.x - endPoint.x) * (startPoint.x - endPoint.x) + (startPoint.y - endPoint.y) * (startPoint.y - endPoint.y));
}