// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__15960BEB_2785_49CA_8B8C_C8DFBF5F6FC4__INCLUDED_)
#define AFX_RECTANGLE_H__15960BEB_2785_49CA_8B8C_C8DFBF5F6FC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "AreaShape.h"

class CRectangle :virtual public CAreaShape  
{
public:
	static int ShapeAmount;
	CRectangle();
	CRectangle(int p_lineType,COLORREF p_borderColor,COLORREF p_fillColor,CPoint p_startPoint,CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Square();
	virtual void Revolve();
	virtual ~CRectangle();

};

#endif // !defined(AFX_RECTANGLE_H__15960BEB_2785_49CA_8B8C_C8DFBF5F6FC4__INCLUDED_)
