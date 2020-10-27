// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__8300FFFF_8122_450A_A291_38E86DD8C994__INCLUDED_)
#define AFX_LINE_H__8300FFFF_8122_450A_A291_38E86DD8C994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Shape.h"
#include "LineShape.h"


class CLine :virtual public CLineShape
{
public:
	static int ShapeAmount;
	CLine();
	CLine(COLORREF p_borderColor,COLORREF p_fillColor,CPoint p_startPoint,CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Node();
	virtual ~CLine();

};

#endif // !defined(AFX_LINE_H__8300FFFF_8122_450A_A291_38E86DD8C994__INCLUDED_)
