// Ellipse.cpp: implementation of the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Ellipse.h"
#include "Shape.h"

//#ifdef _DEBUG
//#undef THIS_FILE
//static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
//#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


int CEllipse::ShapeAmount = 0;//

CEllipse::CEllipse()
{

	setShapeType(ELLIPSE);
	
}
CEllipse::CEllipse(COLORREF p_borderColor,
	  COLORREF p_fillColor,
	  CPoint p_startPoint,
	  CPoint p_endPoint):
	CShape(p_borderColor,p_fillColor,p_startPoint,p_endPoint)
{
	ShapeAmount++;
	setShapeType(ELLIPSE);
}

//@funcName <draw>
//@statement <根据数据绘制图形>
//@parameter <被绘制设备上下文:CDC>
void CEllipse::draw(CDC* pDC)
{
		//创建临时画笔，用于边框颜色
		CPen pen;
		pen.CreatePen(PS_SOLID,1,borderColor);
		pDC->SelectObject(&pen);//把画笔选入设备
		//创建临时画刷，用于填充颜色
		CBrush brush;
		brush.CreateSolidBrush(fillColor);
		pDC->SelectObject(&brush);
		//绘制
		pDC->Ellipse(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
		//删除临时工具
		pen.DeleteObject();
		brush.DeleteObject(); 
		//TRACE("%d %d %d %d", startPoint.x,startPoint.y, endPoint.x, endPoint.y);
		//TRACE("%d %d", Length(),Square());
}


int CEllipse::Square()
{
	return  3.14 * abs((int(startPoint.x) -int(endPoint.x))*(int(startPoint.y)-int(endPoint.y)))/400;//椭圆面积计算 边长1：10；
}

int CEllipse::Length()
{
	int a = (int(startPoint.x) - int(endPoint.x))/2;
	int b = (int(startPoint.y) - int(endPoint.y))/2;
	int temp;
	if (a < b) { temp = a; a = b; b = temp; }
	return (2 * 3.14 * b + (a - b)*4)/10;


}





CEllipse::~CEllipse()
{

}
