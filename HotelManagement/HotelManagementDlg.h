// HotelManagementDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "HotelRoom.h"
#include "LiveRecord.h"
#include "CostRecord.h"
#include "SkinPPWTL.h"


// CHotelManagementDlg �Ի���
class CHotelManagementDlg : public CDialog
{
// ����
public:
	CHotelManagementDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HOTELMANAGEMENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
