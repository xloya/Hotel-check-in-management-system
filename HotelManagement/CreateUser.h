#pragma once


// CCreateUser �Ի���

class CCreateUser : public CDialog
{
	DECLARE_DYNAMIC(CCreateUser)

public:
	CCreateUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreateUser();

// �Ի�������
	enum { IDD = IDD_CreateUser };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_CreateManagementPasswordEdit;
	CString m_CreateUserNameEdit;
	CString m_CreateUserPasswordEdit;
	CString m_CreateUserPassword2Edit;
	afx_msg void OnBnClickedOk();
};
