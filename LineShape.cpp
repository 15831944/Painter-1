#include "stdafx.h"
#include "LineShape.h"


int CLineShape::PythagorenTheorem(CPoint point_1,CPoint point_2) {
	return sqrt((point_2.x - point_2.x) * (point_1.x - point_2.x) + (point_1.y - point_2.y) * (point_1.y - point_2.y));
}