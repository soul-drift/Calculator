
// CalculationDlg.h: 头文件
//

#pragma once

//运算符
enum CALCULATOR_FLAG {
	FLAG_JIA = 0,
	FLAG_JIAN,
	FLAG_CHENG,
	FLAG_CHU,
	FLAG_PINGFANG,
	FLAG_KAIFANG,
	FLAG_DAOSHU,
};
// CCalculationDlg 对话框
class CCalculationDlg : public CDialogEx
{
// 构造
public:
	CCalculationDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonPiont();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonDs();
	afx_msg void OnBnClickedButtonPf();
	afx_msg void OnBnClickedButtonGh();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonAc();
	CString mstr;
	void SaveFirstValue();
	double mnum1;
	double mnum2;
	CALCULATOR_FLAG mFlag;
	void Calculator();
	CString mstr2;
};
