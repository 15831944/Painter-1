#include "stdafx.h"
#include "Polygon.h"
int CPolygon::ShapeAmount = 0;
CPolygon::CPolygon()
{
	setShapeType(POLYGON);
}
CPolygon::CPolygon(COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint) :
	CShape(p_borderColor, p_fillColor, p_startPoint, p_endPoint)
{
	ShapeAmount++;
	setShapeType(POLYGON);
}
void CPolygon::AddNode(CPoint TempNode) {
	LineNode.push_back(TempNode);

};


//@funcName <draw>
//@statement <根据数据绘制图形>
//@parameter <被绘制设备上下文:CDC>
void CPolygon::draw(CDC* pDC)
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
	/*if (LineNode.empty()) {
		pDC->MoveTo(startPoint);
		pDC->LineTo(endPoint);
	}
	else {
		int i = 0;
		pDC->MoveTo(startPoint);
		pDC->LineTo(LineNode[0]);
		for (i = 0; i < LineNode.size() - 1; i++) {
			pDC->MoveTo(LineNode[i]);
			pDC->LineTo(LineNode[i + 1]);
		}
		pDC->MoveTo(LineNode[i]);
		pDC->LineTo(endPoint);
		pDC->MoveTo(endPoint);
		pDC->LineTo(startPoint);
	}*/

	std::vector<CPoint> AllPoint(LineNode);				//该变量用以储存多边形全部顶点
	AllPoint.insert(AllPoint.begin(), startPoint);
	AllPoint.push_back(endPoint);
	pDC->Polygon(&AllPoint[0], AllPoint.size());

	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject();

}


int CPolygon::Length() {
	int i, l = 0;
	l = PointLine(startPoint, LineNode[0]);
	for (i = 0; i < LineNode.size() - 1; i++) {
		l += PointLine(LineNode[i], LineNode[i + 1]);
	}
	l += PointLine(LineNode[i], endPoint);
	l += PointLine(endPoint, startPoint);
	return l;
}
int CPolygon::Square() {
	int i, s = 0;
	if (LineNode.size() >= 3) {
		s = ThreePointSquare(startPoint, LineNode[0], LineNode[1]);
		TRACE("s=%d ", s);
		for (i = 0; i < LineNode.size() - 2; i++) {
			s += ThreePointSquare(LineNode[i], LineNode[i + 1], LineNode[i + 2]);
		}
		s += ThreePointSquare(LineNode[i], startPoint, endPoint);
	}
	else if (LineNode.size() == 0) {
		s = 0;
	}
	else if (LineNode.size() == 1) {
		s = ThreePointSquare(startPoint, LineNode[0],endPoint);
	}
	else if (LineNode.size() == 2) {
		s = ThreePointSquare(startPoint, LineNode[0], LineNode[1])+  ThreePointSquare(startPoint, LineNode[1], endPoint);
	}
	return s;
}



CPolygon::~CPolygon()
{

}