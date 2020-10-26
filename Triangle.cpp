#include "stdafx.h"
#include "Painter.h"
#include "Triangle.h"
#include "Shape.h"

int CTriangle::ShapeAmount = 0;//

CTriangle::CTriangle()
{

	setShapeType(TRIANGLE);

}
CTriangle::CTriangle(COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint) :
	CShape(p_borderColor, p_fillColor, p_startPoint, p_endPoint)
{
	ShapeAmount++;
	setShapeType(TRIANGLE);
}

//@funcName <draw>
//@statement <根据数据绘制图形>
//@parameter <被绘制设备上下文:CDC>
void CTriangle::draw(CDC* pDC)
{
	;
	//创建临时画笔，用于边框颜色
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, borderColor);
	pDC->SelectObject(&pen);//把画笔选入设备
	//创建临时画刷，用于填充颜色
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//绘制
	CPoint Pt[3];
	Pt[0] = CPoint(startPoint.x, endPoint.y);
	Pt[1] = CPoint((startPoint.x+endPoint.x)/2, startPoint.y);
	Pt[2] = CPoint(endPoint.x, endPoint.y);
	pDC->Polygon(Pt,3);
	//pDC->Ellipse(startPoint.x, startPoint.y, startPoint.x + endPoint.y - startPoint.y, endPoint.y);
	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject();
	//TRACE("%d %d %d %d", startPoint.x,startPoint.y, endPoint.x, endPoint.y);
	//TRACE("%d %d", Length(), Square());

}


int CTriangle::Square()
{
	return  (endPoint.x - startPoint.x) * (endPoint.y - startPoint.y) / 200;//圆形面积计算 边长1：10；
}

int CTriangle::Length()
{
	int h = endPoint.y - startPoint.y;
	int d = (endPoint.x - startPoint.x) / 2;
	int l = sqrt(h * h + d * d);
	return (l+d) / 5;


}





CTriangle::~CTriangle()
{

}
