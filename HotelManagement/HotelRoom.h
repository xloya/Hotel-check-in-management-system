#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// HotelRoom 对话框

class HotelRoom : public CDialog
{
	DECLARE_DYNAMIC(HotelRoom)

public:
	HotelRoom(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HotelRoom();

// 对话框数据
	enum { IDD = IDD_HotelRoom };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CComboBox m_ComboBox;
};
