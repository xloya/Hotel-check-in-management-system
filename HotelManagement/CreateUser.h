#pragma once


// CCreateUser 对话框

class CCreateUser : public CDialog
{
	DECLARE_DYNAMIC(CCreateUser)

public:
	CCreateUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreateUser();

// 对话框数据
	enum { IDD = IDD_CreateUser };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_CreateManagementPasswordEdit;
	CString m_CreateUserNameEdit;
	CString m_CreateUserPasswordEdit;
	CString m_CreateUserPassword2Edit;
	afx_msg void OnBnClickedOk();
};
