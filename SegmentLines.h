#pragma once
//#include "SegmentLines.h"
#include <vector>
#include "LineShape.h"
#include "Shape.h"

class CSegmentLines :virtual public CLineShape
 
{
public:
	static int ShapeAmount;
	//std::vector<CPoint> LineNode; //创建vector用于储存节点
	

	CSegmentLines();
	CSegmentLines(int p_lineType,COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	void AddNode(CPoint TempNode) ;
	virtual int Length();
	virtual int Node();
	virtual ~CSegmentLines();
};

