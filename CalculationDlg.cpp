
// CalculationDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculation.h"
#include "CalculationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculationDlg 对话框



CCalculationDlg::CCalculationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATION_DIALOG, pParent)
	, mstr(_T(""))
	, mstr2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mstr);
	DDX_Text(pDX, IDC_EDIT2, mstr2);
}

BEGIN_MESSAGE_MAP(CCalculationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculationDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculationDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculationDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculationDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculationDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculationDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculationDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculationDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_PIONT, &CCalculationDlg::OnBnClickedButtonPiont)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculationDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalculationDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculationDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculationDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculationDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_DS, &CCalculationDlg::OnBnClickedButtonDs)
	ON_BN_CLICKED(IDC_BUTTON_PF, &CCalculationDlg::OnBnClickedButtonPf)
	ON_BN_CLICKED(IDC_BUTTON_GH, &CCalculationDlg::OnBnClickedButtonGh)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalculationDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_AC, &CCalculationDlg::OnBnClickedButtonAc)
END_MESSAGE_MAP()


// CCalculationDlg 消息处理程序

BOOL CCalculationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculationDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	mstr += "1";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	mstr += "2";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	mstr += "3";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	mstr += "4";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	mstr += "5";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	mstr += "6";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton7()
{
	UpdateData(TRUE);
	mstr += "7";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton8()
{
	UpdateData(TRUE);
	mstr += "8";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	mstr += "9";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButton0()
{
	UpdateData(TRUE);
	mstr += "0";
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButtonPiont()
{
	UpdateData(TRUE);
	if (-1 == mstr.Find('.'))
	{
		mstr += ".";
	}
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButtonAdd()
{
	SaveFirstValue();
	mFlag = FLAG_JIA;
}


void CCalculationDlg::OnBnClickedButtonSub()
{
	SaveFirstValue();
	mFlag = FLAG_JIAN;
}


void CCalculationDlg::OnBnClickedButtonMul()
{
	SaveFirstValue();
	mFlag = FLAG_CHENG;
}


void CCalculationDlg::OnBnClickedButtonDiv()
{
	SaveFirstValue();
	mFlag = FLAG_CHU;
}


void CCalculationDlg::OnBnClickedButtonEqual()
{
	Calculator();
}


void CCalculationDlg::OnBnClickedButtonDs()
{
	UpdateData(TRUE);
	mnum1 = _wtof(mstr);
	double f = 1/mnum1;
	//如果浮点数其实是个整数,就显示为整数
	if (f - int(f) <= 1e-5)
	{
		mstr.Format(L"%d", (int)f);
	}
	else
	{
		mstr.Format(L"%f", f);
	}
	UpdateData(FALSE);

	mnum1 = f;
	mnum2 = 0.0f;
	mFlag = FLAG_DAOSHU;
}


void CCalculationDlg::OnBnClickedButtonPf()
{
	UpdateData(TRUE);
	mnum1 = _wtof(mstr);
	double f = mnum1 * mnum1;
	//如果浮点数其实是个整数,就显示为整数
	if (f - int(f) <= 1e-5)
	{
		mstr.Format(L"%d", (int)f);
	}
	else
	{
		mstr.Format(L"%f", f);
	}
	UpdateData(FALSE);

	mnum1 = f;
	mnum2 = 0.0f;
	mFlag = FLAG_PINGFANG;
}


void CCalculationDlg::OnBnClickedButtonGh()
{
	UpdateData(TRUE);
	mnum1 = _wtof(mstr);
	double f = sqrt(mnum1);
	//如果浮点数其实是个整数,就显示为整数
	if (f - int(f) <= 1e-5)
	{
		mstr.Format(L"%d", (int)f);
	}
	else
	{
		mstr.Format(L"%f", f);
	}
	UpdateData(FALSE);

	mnum1 = f;
	mnum2 = 0.0f;
	mFlag = FLAG_KAIFANG;
}


void CCalculationDlg::OnBnClickedButtonDel()
{
	UpdateData(TRUE);
	//移除最右边一个字符  
	if (!mstr.IsEmpty())
	{
		mstr = mstr.Left(mstr.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CCalculationDlg::OnBnClickedButtonAc()
{
	UpdateData(TRUE);
	mstr = "";
	mnum1 = 0.0f;
	mnum2 = 0.0f;
	mFlag = FLAG_JIA;
	mstr2 = "";
	UpdateData(FALSE);
}

void CCalculationDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	mstr2 = mstr;
	mnum1 = _wtof(mstr);
	mstr = "";
	UpdateData(FALSE);
}

void CCalculationDlg::Calculator()
{
	UpdateData(TRUE);
	mnum2 = _wtof(mstr);
	double result = 0.0f;
	switch (mFlag)
	{
	case FLAG_JIA:						//加  
		result = mnum1 + mnum2;
		break;
	case FLAG_JIAN:						//减 
		result = mnum1 - mnum2;
		break;
	case FLAG_CHENG:					//乘  
		result = mnum1 * mnum2;
		break;
	case FLAG_CHU:						//除  
		if (mnum2 == 0.0f)
		{
			result = mnum1;
		}
		else
		{
			result = mnum1 / mnum2;
		}
		break;
	case FLAG_PINGFANG:					//平方 
		result = mnum2 * mnum2;
		break;
	case FLAG_KAIFANG:					//开方  
		result = sqrt(mnum2);
		break;
	case FLAG_DAOSHU:					//倒数
		result = 1/mnum2;
		break;
	default:
		break;
	}
	//如果浮点数其实是个整数,就显示为整数
	if (result - int(result) <= 1e-5)
	{
		mstr.Format(L"%d", (int)result);
	}
	else
	{
		mstr.Format(L"%f", result);
	}
	mstr2 = "";
	UpdateData(FALSE);

	mnum1 = result;
	mnum2 = 0.0f;
}
