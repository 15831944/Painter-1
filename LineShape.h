
#include "stdafx.h"
#include "AreaShape.h"


#pragma once
class CLineShape :
   virtual public CShape
{
public:
	CPoint PointRevolve(CPoint point_1, CPoint point_2);//处理返回point_1绕point_2旋转90度后的点
	int PythagorenTheorem(CPoint point_1, CPoint point_2);//勾股定理
	int getNode(){}
};

