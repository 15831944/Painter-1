#include "stdafx.h"
#include "LineShape.h"


int CLineShape::PythagorenTheorem(CPoint point_1,CPoint point_2) {
	return sqrt((point_1.x - point_2.x) * (point_1.x - point_2.x) + (point_1.y - point_2.y) * (point_1.y - point_2.y)) / 10;
}


CPoint CLineShape::PointRevolve(CPoint point_1, CPoint point_2) {
	CPoint tempPoint, resultPoint;
	tempPoint.x = point_1.x - point_2.x;
	tempPoint.y = point_1.y - point_2.y;
	resultPoint.x = point_2.x - tempPoint.y;
	resultPoint.y = point_2.y + tempPoint.x;
	return resultPoint;


}