#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CostRecord 对话框

class CostRecord : public CDialog
{
	DECLARE_DYNAMIC(CostRecord)

public:
	CostRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CostRecord();

// 对话框数据
	enum { IDD = IDD_CostRecord };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedButton1();
};
