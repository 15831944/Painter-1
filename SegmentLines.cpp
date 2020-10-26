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
//@statement <根据数据绘制图形>
//@parameter <被绘制设备上下文:CDC>
void CSegmentLines::draw(CDC* pDC)
{
	//创建临时画笔，用于边框颜色
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, borderColor);
	pDC->SelectObject(&pen);//把画笔选入设备
	//创建临时画刷，用于填充颜色
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//绘制
	pDC->MoveTo(startPoint);
	pDC->LineTo(endPoint);
	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject();

}
CSegmentLines::~CSegmentLines()
{

}
