#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CostRecord �Ի���

class CostRecord : public CDialog
{
	DECLARE_DYNAMIC(CostRecord)

public:
	CostRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CostRecord();

// �Ի�������
	enum { IDD = IDD_CostRecord };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedButton1();
};
