#pragma once
#include "afxwin.h"


// CFindPassWord �Ի���

class CFindPassWord : public CDialog
{
	DECLARE_DYNAMIC(CFindPassWord)

public:
	CFindPassWord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindPassWord();

// �Ի�������
	enum { IDD = IDD_FindPassword };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_FindManagePasswordEdit;
	CString m_FindUserNameEdit;
	CEdit m_FindUserPasswordEdit;
	CString m_FindUserPassword2Edit;
	afx_msg void OnBnClickedOk();
	CString m_FindUserPasswordEdit1;
};
