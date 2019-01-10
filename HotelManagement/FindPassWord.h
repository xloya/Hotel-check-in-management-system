#pragma once
#include "afxwin.h"


// CFindPassWord 对话框

class CFindPassWord : public CDialog
{
	DECLARE_DYNAMIC(CFindPassWord)

public:
	CFindPassWord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFindPassWord();

// 对话框数据
	enum { IDD = IDD_FindPassword };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_FindManagePasswordEdit;
	CString m_FindUserNameEdit;
	CEdit m_FindUserPasswordEdit;
	CString m_FindUserPassword2Edit;
	afx_msg void OnBnClickedOk();
	CString m_FindUserPasswordEdit1;
};
