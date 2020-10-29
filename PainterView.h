// PainterView.h : interface of the CPainterView class
//
/////////////////////////////////////////////////////////////////////////////
#include"PainterDoc.h"
#if !defined(AFX_PAINTERVIEW_H__3101891E_6B64_4F58_B0E2_BAA9BEC5DC72__INCLUDED_)
#define AFX_PAINTERVIEW_H__3101891E_6B64_4F58_B0E2_BAA9BEC5DC72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPainterView : public CView
{

protected://�������
	//�˵�ѡ��
	int m_lineType;
	COLORREF m_borderColor;//�߿���ɫ
	COLORREF m_fillColor;//�����ɫ
	enum shapeType{UNSURE,LINE,RECTANGLE,ELLIPSE,CIRCLE,TRIANGLE, POLYGON, SEGMENTLINES};//��״����
	shapeType m_shapeType;
	//״̬
	int m_shapeState;//1Ϊ��ͼ��2Ϊ�ƶ���3Ϊ��ת
	int m_drawState;//1Ϊ���ڻ���0Ϊû�ڻ�
	CPoint LastMousePoint;//�ı��������ƶ��м�¼�ϴ����λ��
protected: // create from serialization only
	CPainterView();
	DECLARE_DYNCREATE(CPainterView)

// Attributes
public:
	CPainterDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPainterView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPainterView)
	afx_msg void OnShapeLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeEllipse();
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorRed();
	afx_msg void OnFillcolorBlack();
	afx_msg void OnFillcolorBlue();
	afx_msg void OnFillcolorGreen();
	afx_msg void OnFillcolorRed();
	afx_msg void OnUpdateShapeLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFillcolorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFillcolorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFillcolorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFillcolorRed(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnClear();
	afx_msg void OnFillcolorWhite();
	afx_msg void OnUpdateFillcolorWhite(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShapeCircle();
	afx_msg void OnUpdateShapeCircle(CCmdUI* pCmdUI);
	afx_msg void OnShapeTriangle();
	afx_msg void OnUpdateShapeTriangle(CCmdUI* pCmdUI);
	afx_msg void OnShapeSegmentlines();
	afx_msg void OnUpdateShapeSegmentlines(CCmdUI* pCmdUI);
	afx_msg void OnShapePolygon();
	afx_msg void OnUpdateShapePolygon(CCmdUI* pCmdUI);
	afx_msg void OnTest();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShapeDraw();
	afx_msg void OnShapeMove();
	afx_msg void OnShapeRevolve();
	afx_msg void OnUpdateShapeMove(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeRevolve(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeDraw(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeSolid();
	afx_msg void OnUpdateLinetypeSolid(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeDash();
	afx_msg void OnUpdateLinetypeDash(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeDot();
	afx_msg void OnUpdateLinetypeDot(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeDashdot();
	afx_msg void OnUpdateLinetypeDashdot(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeDashdotdot();
	afx_msg void OnUpdateLinetypeDashdotdot(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLinetypeInsideframe(CCmdUI* pCmdUI);
	afx_msg void OnLinetypeInsideframe();
	afx_msg void OnShapeAlter();
};

#ifndef _DEBUG  // debug version in PainterView.cpp
inline CPainterDoc* CPainterView::GetDocument()
   { return (CPainterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTERVIEW_H__3101891E_6B64_4F58_B0E2_BAA9BEC5DC72__INCLUDED_)
