// HotelManagementDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#include "HotelRoom.h"
#include "LiveRecord.h"
#include "CostRecord.h"
#include "SkinPPWTL.h"


// CHotelManagementDlg 对话框
class CHotelManagementDlg : public CDialog
{
// 构造
public:
	CHotelManagementDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HOTELMANAGEMENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tab;
	HotelRoom page1;
	CostRecord page3;
	LiveRecord page2;
};
