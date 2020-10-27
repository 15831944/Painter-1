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
	if (LineNode.empty()) {
		pDC->MoveTo(startPoint);
		pDC->LineTo(endPoint);
	}
	else {
		int i = 0;
		pDC->MoveTo(startPoint);
		pDC->LineTo(LineNode[0]);
		for (i=0; i < LineNode.size()-1; i++) {
			pDC->MoveTo(LineNode[i]);
			pDC->LineTo(LineNode[i+1]);
		}
		pDC->MoveTo(LineNode[i]);
		pDC->LineTo(endPoint);
	}
	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject(); 

}

int CSegmentLines::Length()
{
	int length=0;
	if (LineNode.empty()) {
		length = PythagorenTheorem(startPoint, endPoint);
	}
	else {
		int i = 0;
		length = PythagorenTheorem(startPoint, LineNode[0]);
		for (i = 0; i < LineNode.size() - 1; i++) {
			length += PythagorenTheorem(LineNode[i], LineNode[i+1]);
		}
		length += PythagorenTheorem(LineNode[i], endPoint);
	}
	return length;
}

int CSegmentLines::Node()
{
	return  getLineNode()+2;//；
}



CSegmentLines::~CSegmentLines()
{

}
