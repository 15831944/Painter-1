#include "stdafx.h"
#include "AreaShape.h"

int CAreaShape::ThreePointSquare(CPoint point_1, CPoint point_2, CPoint point_3) {
	int temp =  abs(point_1.x * point_2.y + point_2.x * point_3.y + point_3.x * point_1.y - point_2.x * point_1.y - point_3.x * point_2.y - point_1.x * point_3.y) / 100/2;
	//TRACE("d");
	return temp;
}//返回三点所围成的面积



int CAreaShape::PointLine(CPoint point_1, CPoint point_2) {
	return sqrt((point_1.x - point_2.x) * (point_1.x - point_2.x) + (point_1.y - point_2.y) * (point_1.y - point_2.y)) / 10;
}//返回两点长度