#pragma once
#include "AreaShape.h"
#include <vector>

class CSegmentLines :
    public CShape
{
public:
	static int ShapeAmount;
	//std::vector<CPoint> LineNode; //创建vector用于储存节点
	

	CSegmentLines();
	CSegmentLines(COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	void AddNode(CPoint TempNode) ;

	virtual ~CSegmentLines();
};

