#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// HotelRoom �Ի���

class HotelRoom : public CDialog
{
	DECLARE_DYNAMIC(HotelRoom)

public:
	HotelRoom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HotelRoom();

// �Ի�������
	enum { IDD = IDD_HotelRoom };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CComboBox m_ComboBox;
};
