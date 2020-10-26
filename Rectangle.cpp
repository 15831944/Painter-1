// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CRectangle::ShapeAmount=0;

CRectangle::CRectangle()
{
	setShapeType(RECTANGLE);
}
CRectangle::CRectangle(COLORREF p_borderColor,
	  COLORREF p_fillColor,
	  CPoint p_startPoint,
	  CPoint p_endPoint):
	CShape(p_borderColor,p_fillColor,p_startPoint,p_endPoint)
{
	ShapeAmount++;
	setShapeType(RECTANGLE);
}

//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CRectangle:: draw(CDC* pDC)
{
		//������ʱ���ʣ����ڱ߿���ɫ
		CPen pen;
		pen.CreatePen(PS_SOLID,1,borderColor);
		pDC->SelectObject(&pen);//�ѻ���ѡ���豸
		//������ʱ��ˢ�����������ɫ
		CBrush brush;
		brush.CreateSolidBrush(fillColor);
		pDC->SelectObject(&brush);
		//����
		pDC->Rectangle(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
		//ɾ����ʱ����
		pen.DeleteObject();
		brush.DeleteObject(); 
		//TRACE("%d %d", Length(), Square());

}

int CRectangle::Square()
{
	return   abs((int(startPoint.x) - int(endPoint.x)) * (int(startPoint.y) - int(endPoint.y))) / 100;
}

int CRectangle::Length()
{

	return   abs((int(startPoint.x) - int(endPoint.x)) +(int(startPoint.y) - int(endPoint.y))) / 10*2;

}


CRectangle::~CRectangle()
{

}
