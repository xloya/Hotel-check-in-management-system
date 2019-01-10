// HotelManagementDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "HotelManagementDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CHotelManagementDlg �Ի���




CHotelManagementDlg::CHotelManagementDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHotelManagementDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHotelManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CHotelManagementDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CHotelManagementDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CHotelManagementDlg ��Ϣ�������
void CHotelManagementDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRect r;
	m_tab.GetClientRect (&r);
	switch(m_tab.GetCurSel())//��ȡ��굥����ѡ�.
	{
	case 0:
		{
			page1.ShowWindow(TRUE);//��ʾ��굥����ѡ���Ӧ����.
			page2.ShowWindow(FALSE);
			page3.ShowWindow(FALSE);
			break;
		}
	case 1:
		{
			page1.ShowWindow(FALSE);
			page2.ShowWindow(TRUE);
			page3.ShowWindow(FALSE);
			break;
		}
	case 2:
		{
			page1.ShowWindow(FALSE);
			page2.ShowWindow(FALSE);
			page3.ShowWindow(TRUE);
			break;
		}
	}
	*pResult = 0;
}

BOOL CHotelManagementDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0,"�ͷ���Ϣ");
	m_tab.InsertItem(1,"��ס����");
	m_tab.InsertItem(2,"���ü�¼");

	page1.Create(IDD_HotelRoom,GetDlgItem(IDC_TAB1));
	page2.Create(IDD_LiveRecord,GetDlgItem(IDC_TAB1));
	page3.Create(IDD_CostRecord,GetDlgItem(IDC_TAB1));

	page1.SetParent(GetDlgItem(IDC_TAB1));
	page2.SetParent(GetDlgItem(IDC_TAB1));
	page3.SetParent(GetDlgItem(IDC_TAB1));

	RECT r1;
	r1.left=1;
	r1.top=22;
	r1.bottom=1000;
	r1.right=1000;

	page1.MoveWindow(&r1);
	page2.MoveWindow(&r1);
	page3.MoveWindow(&r1);
                      //---------Ĭ����ʾpage1                     
	page1.ShowWindow(TRUE);

//-----��ӱ���ֶ�------------------------
	page1.m_list.InsertColumn(0,_T("����"),200);
	page1.m_list.InsertColumn(1,_T("�۸�"),200);
	page1.m_list.InsertColumn(2,_T("λ��"),200);
	page1.m_list.InsertColumn(3,_T("�Ƿ�Ϊ��"),200);		
	page1.m_list.SetColumnWidth(0, 100);
	page1.m_list.SetColumnWidth(1, 100);
	page1.m_list.SetColumnWidth(2, 100);
	page1.m_list.SetColumnWidth(3, 100);

	page2.m_list.InsertColumn(0,_T("��������"),200);
	page2.m_list.InsertColumn(1,_T("�������֤"),200);
	page2.m_list.InsertColumn(2,_T("���˵绰"),200);
	page2.m_list.InsertColumn(3,_T("�ͷ�λ��"),200);	
	page2.m_list.InsertColumn(4,_T("����"),200);
	page2.m_list.InsertColumn(5,_T("��סʱ��"),200);
	page2.m_list.InsertColumn(6,_T("��ס����"),200);
	page2.m_list.SetColumnWidth(0, 100);
	page2.m_list.SetColumnWidth(1, 150);
	page2.m_list.SetColumnWidth(2, 100);
	page2.m_list.SetColumnWidth(3, 100);
	page2.m_list.SetColumnWidth(4, 100);
	page2.m_list.SetColumnWidth(5, 100);
	page2.m_list.SetColumnWidth(6, 100);

	page3.m_list.InsertColumn(0,_T("��������"),200);
	page3.m_list.InsertColumn(1,_T("�������֤"),200);
	page3.m_list.InsertColumn(2,_T("���˵绰"),200);
	page3.m_list.InsertColumn(3,_T("�ͷ�λ��"),200);
	page3.m_list.InsertColumn(4,_T("��סʱ��"),200);	
	page3.m_list.InsertColumn(5,_T("�˷�ʱ��"),200);
	page3.m_list.InsertColumn(6,_T("��ס����"),200);
	page3.m_list.SetColumnWidth(0, 100);
	page3.m_list.SetColumnWidth(1, 150);
	page3.m_list.SetColumnWidth(2, 100);
	page3.m_list.SetColumnWidth(3, 100);
	page3.m_list.SetColumnWidth(4, 100);
	page3.m_list.SetColumnWidth(5, 100);
	page3.m_list.SetColumnWidth(6, 100);




	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHotelManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHotelManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHotelManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


