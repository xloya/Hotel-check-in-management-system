#pragma once
#include "FindPassword.h"
#include "CreateUser.h"

// CLogin �Ի���

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogin();

// �Ի�������
	enum { IDD = IDD_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_LoginUserNameEdit;
	CString m_LoginUserPasswordEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedLogincreateuserbutton();
	afx_msg void OnBnClickedLoginfindpasswirdbutton();
};
