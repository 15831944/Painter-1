#include "stdafx.h"
#include "SegmentLines.h"


int CSegmentLines::ShapeAmount = 0;
CSegmentLines::CSegmentLines()
{
	setShapeType(SEGMENTLINES);
}
CSegmentLines::CSegmentLines(COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint) :
	CShape(p_borderColor, p_fillColor, p_startPoint, p_endPoint)
{
	ShapeAmount++;
	setShapeType(SEGMENTLINES);
}
void CSegmentLines::AddNode(CPoint TempNode) {
	LineNode.push_back(TempNode);

};


//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CSegmentLines::draw(CDC* pDC)
{
	//������ʱ���ʣ����ڱ߿���ɫ
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, borderColor);
	pDC->SelectObject(&pen);//�ѻ���ѡ���豸
	//������ʱ��ˢ�����������ɫ
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//����
	pDC->MoveTo(startPoint);
	pDC->LineTo(endPoint);
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();

}
CSegmentLines::~CSegmentLines()
{

}
