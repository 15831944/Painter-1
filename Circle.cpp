//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Circle.h"
#include "Shape.h"

int CCircle::ShapeAmount = 0;//

CCircle::CCircle()
{

	setShapeType(CIRCLE);

}
CCircle::CCircle(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint)
{
	ShapeAmount++;
	setShapeType(CIRCLE);
}

//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CCircle::draw(CDC* pDC)
{
	;
	//������ʱ���ʣ����ڱ߿���ɫ
	CPen pen;
	pen.CreatePen(lineType, 1, borderColor);
	pDC->SelectObject(&pen);//�ѻ���ѡ���豸
	//������ʱ��ˢ�����������ɫ
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//����
	//CPoint Pt[3];
	//Pt[0] = CPoint(startPoint.x, startPoint.y);
	//Pt[1] = CPoint(endPoint.x, endPoint.y);
	//Pt[2] = CPoint(startPoint.x, endPoint.y);
	//pDC->Polygon(Pt,3);
	pDC->Ellipse(startPoint.x, startPoint.y, startPoint.x + endPoint.y- startPoint.y, endPoint.y);
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();
	//TRACE("%d %d %d %d", startPoint.x,startPoint.y, endPoint.x, endPoint.y);
	//TRACE("%d %d", Length(),Square());

}


int CCircle::Square()
{
	return  3.14 * (endPoint.x - startPoint.x) * (endPoint.x - startPoint.x) / 400;//Բ��������� �߳�1��10��
}

int CCircle::Length()
{
	return 3.14 * abs(endPoint.x - startPoint.x)/10;


}





CCircle::~CCircle()
{

}
