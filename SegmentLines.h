#pragma once
#include "AreaShape.h"
#include <vector>

class CSegmentLines :
    public CAreaShape
{
public:
	static int ShapeAmount;
	std::vector<CPoint> LineNode; //����vector���ڴ���ڵ�


	CSegmentLines();
	CSegmentLines(COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);

	virtual ~CSegmentLines();
};

