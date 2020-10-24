#pragma once
#include "AreaShape.h"
class CSegmentLines :
    public CAreaShape
{
public:
	static int ShapeAmount;
	CSegmentLines();
	CSegmentLines(COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);

	virtual ~CSegmentLines();
};

