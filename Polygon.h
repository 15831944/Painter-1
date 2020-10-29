#pragma once
#include "AreaShape.h"

class CPolygon :
	public CAreaShape
{
public:
	static int ShapeAmount;
	//std::vector<CPoint> LineNode; //����vector���ڴ���ڵ�


	CPolygon();
	CPolygon(int p_lineType,COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	virtual int Length();
	virtual int Square();
	void draw(CDC* pDC);
	void AddNode(CPoint TempNode);
	virtual ~CPolygon();
};

