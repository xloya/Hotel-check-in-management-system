#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// LiveRecord 对话框

class LiveRecord : public CDialog
{
	DECLARE_DYNAMIC(LiveRecord)

public:
	LiveRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LiveRecord();

// 对话框数据
	enum { IDD = IDD_LiveRecord };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};
