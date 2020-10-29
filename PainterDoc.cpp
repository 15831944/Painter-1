// PainterDoc.cpp : implementation of the CPainterDoc class
//

#include "stdafx.h"
#include "Painter.h"
#include "PainterView.h"
#include "PainterDoc.h"

//形状

#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Rectangle.h"
#include"SegmentLines.h"
#include "Polygon.h"
#include "Triangle.h"

#include <fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc

IMPLEMENT_DYNCREATE(CPainterDoc, CDocument)

BEGIN_MESSAGE_MAP(CPainterDoc, CDocument)
	//{{AFX_MSG_MAP(CPainterDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_INQUIRE_NUM, &CPainterDoc::OnInquireNum)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc construction/destruction

CPainterDoc::CPainterDoc()
{
	// TODO: add one-time construction code here

}
//@funcName <CPainterDoc::draw>
//@statement <根据shapes内容绘制所有图形>
//@parameter <被绘制设备上下文:CDC>
void CPainterDoc::draw(CDC *pDC)
{
	//POSITION pos = GetFirstViewPosition();

	//CView* pView = GetNextView(pos);
	//CClientDC pDC(pView);
	for(size_t i=0;i<shapes.size();i++)
	{
		shapes[i]->draw(pDC);
	}
}

CPainterDoc::~CPainterDoc()
{
	for(size_t i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}
//@funcName <clear>
//@statement <清除画板内容>
void CPainterDoc::clear()
{
	while(!shapes.empty())
	{
		delete shapes[0];
		shapes.erase(shapes.begin());//删除这个指针
	}
	
}

BOOL CPainterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPainterDoc serialization

void CPainterDoc::ShapeInfShow() {


}

void CPainterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc diagnostics

#ifdef _DEBUG
void CPainterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPainterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc commands

void CPainterDoc::OnFileSave() 
{
	// TODO: Add your command handler code here

	//使用自带的保存对话框获取路径
	CFileDialog saveDlg(false,TEXT("painter"),TEXT("未命名"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,".painter");
	saveDlg.DoModal();
	CString pathName=saveDlg.GetPathName();
	
	if(pathName=="") return;//如果直接关掉窗口


	//保存到文件中
	CStdioFile fout;
	CString buffer;//写文件缓冲区
	if(!fout.Open(pathName,CFile::modeCreate|CFile::modeWrite))
		return;//如果打开失败就返回
	for(size_t i=0;i<size();i++)
	{
		buffer.Format("%d %d %d %d %d %d %d %d",
				shapes[i]->getShapeType(),
				shapes[i]->getLineType(),
				shapes[i]->getBorderColor(),
				shapes[i]->getFillColor(),
				shapes[i]->getStartPoint().x,
				shapes[i]->getStartPoint().y,
				shapes[i]->getEndPoint().x,
				shapes[i]->getEndPoint().y
				);
	/*	if (shapes[i]->LineNode.size()) {
			for (size_t j = 0; j < size(); j++) {
				buffer.Format(" %d %d",
					shapes[i]->LineNode[j].x,
					shapes[i]->LineNode[j].y
				);
			}
		}
		else{ 
			
		}*/
		if(i!=size()-1)
			buffer+="\n";//最后一行不加换行
		fout.WriteString(buffer);
	}
	fout.Close();
	
}

void CPainterDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	//使用自带的对话框获取路径
	CFileDialog openDlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,NULL);
	openDlg.DoModal();
	CString pathName=openDlg.GetPathName();
	

	if(pathName=="") return;//如果直接关掉窗口
	//读取文件
	using namespace std;
	ifstream fin;
	int lineType;
	COLORREF borderColor;//边框颜色
	COLORREF fillColor;//填充颜色
	CPoint startPoint;//绘制起点
	CPoint endPoint;//绘制终点
	enum shapeType{UNSURE,LINE,RECTANGLE,ELLIPSE,CIRCLE,TRIANGLE, POLYGON, SEGMENTLINES};//形状类型
	int type;//形状

	CShape *newShape=NULL;
	
	clear();//清空画板
	
	fin.open(pathName);
	while(!fin.eof())
	{
		fin>>type
			>>lineType
			>>borderColor
			>>fillColor
			>>startPoint.x
			>>startPoint.y
			>>endPoint.x
			>>endPoint.y;
		switch(type)
		{
		case LINE://直线
			newShape=new CLine(lineType,borderColor,fillColor,startPoint,endPoint);
			
			break;
		case RECTANGLE://矩形
			newShape=new CRectangle(lineType, borderColor, fillColor, startPoint, endPoint);
			
			break;
		case ELLIPSE:
			newShape=new CEllipse(lineType, borderColor, fillColor, startPoint, endPoint);
			break;
		case TRIANGLE://直线
			newShape = new CLine(lineType, borderColor, fillColor, startPoint, endPoint);
			break;
		case CIRCLE://直线
			newShape = new CLine(lineType, borderColor, fillColor, startPoint, endPoint);
			break;

			break;
		}
		push_back(newShape);//添加新形状
	
	}
	POSITION pos = GetFirstViewPosition();

	CView* pView = GetNextView(pos); //得到View指针 
	CClientDC pDC(pView);
	draw(&pDC);
	fin.close();
}




void CPainterDoc::OnInquireNum()
{

	CString StringMessage = _T("");  
	StringMessage.Format(_T("直线数量为%d\n"
							"多段折线数量为%d\n"
							"矩形数量为%d\n"
							"椭圆数量为%d\n"
							"圆形数量为%d\n"
							"三角形数量为%d\n"
							"n边形数量为%d\n"), 
								CLine::ShapeAmount,
								CSegmentLines::ShapeAmount,
								CRectangle::ShapeAmount,
								CEllipse::ShapeAmount,
								CCircle::ShapeAmount,
								CTriangle::ShapeAmount,
								CPolygon::ShapeAmount);
	AfxMessageBox(_T(StringMessage));
	// TODO: 在此添加命令处理程序代码
}
