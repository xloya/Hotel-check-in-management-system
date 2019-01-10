#pragma once
#include "FindPassword.h"
#include "CreateUser.h"

// CLogin 对话框

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogin();

// 对话框数据
	enum { IDD = IDD_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_LoginUserNameEdit;
	CString m_LoginUserPasswordEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedLogincreateuserbutton();
	afx_msg void OnBnClickedLoginfindpasswirdbutton();
};
