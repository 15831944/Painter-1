#pragma once
#include "Shape.h"
class CAreaShape :
    virtual public CShape
{
protected:
    //COLORREF fillColor;//填充颜色
public:
    //COLORREF setFillColor(COLORREF color) { return fillColor = color; }//设置填充颜色
    //COLORREF getFillColor() { return fillColor; }
    //virtual int Length() { return 0; }
    //virtual int Square() { return 0; }
    int ThreePointSquare(CPoint point_1,CPoint point_2, CPoint point_3);//返回三点所围成的面积
    int PointLine(CPoint point_1, CPoint point_2);//返回两点长度
    CPoint PointRevolve(CPoint point_1, CPoint point_2);//处理返回point_1绕point_2旋转90度后的点
};
