
#include "stdafx.h"
#include "AreaShape.h"


#pragma once
class CLineShape :
   virtual public CShape
{
public:
	int PythagorenTheorem(CPoint point_1, CPoint point_2);//���ɶ���
	int getNode(){}
};

