// HotelManagementDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "HotelManagementDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CHotelManagementDlg 对话框




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


// CHotelManagementDlg 消息处理程序
void CHotelManagementDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CRect r;
	m_tab.GetClientRect (&r);
	switch(m_tab.GetCurSel())//获取鼠标单击的选项卡.
	{
	case 0:
		{
			page1.ShowWindow(TRUE);//显示鼠标单击的选项卡对应窗口.
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

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.InsertItem(0,"客房信息");
	m_tab.InsertItem(1,"入住管理");
	m_tab.InsertItem(2,"费用记录");

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
                      //---------默认显示page1                     
	page1.ShowWindow(TRUE);

//-----添加表格字段------------------------
	page1.m_list.InsertColumn(0,_T("类型"),200);
	page1.m_list.InsertColumn(1,_T("价格"),200);
	page1.m_list.InsertColumn(2,_T("位置"),200);
	page1.m_list.InsertColumn(3,_T("是否为空"),200);		
	page1.m_list.SetColumnWidth(0, 100);
	page1.m_list.SetColumnWidth(1, 100);
	page1.m_list.SetColumnWidth(2, 100);
	page1.m_list.SetColumnWidth(3, 100);

	page2.m_list.InsertColumn(0,_T("客人姓名"),200);
	page2.m_list.InsertColumn(1,_T("客人身份证"),200);
	page2.m_list.InsertColumn(2,_T("客人电话"),200);
	page2.m_list.InsertColumn(3,_T("客房位置"),200);	
	page2.m_list.InsertColumn(4,_T("类型"),200);
	page2.m_list.InsertColumn(5,_T("入住时间"),200);
	page2.m_list.InsertColumn(6,_T("入住天数"),200);
	page2.m_list.SetColumnWidth(0, 100);
	page2.m_list.SetColumnWidth(1, 150);
	page2.m_list.SetColumnWidth(2, 100);
	page2.m_list.SetColumnWidth(3, 100);
	page2.m_list.SetColumnWidth(4, 100);
	page2.m_list.SetColumnWidth(5, 100);
	page2.m_list.SetColumnWidth(6, 100);

	page3.m_list.InsertColumn(0,_T("客人姓名"),200);
	page3.m_list.InsertColumn(1,_T("客人身份证"),200);
	page3.m_list.InsertColumn(2,_T("客人电话"),200);
	page3.m_list.InsertColumn(3,_T("客房位置"),200);
	page3.m_list.InsertColumn(4,_T("入住时间"),200);	
	page3.m_list.InsertColumn(5,_T("退房时间"),200);
	page3.m_list.InsertColumn(6,_T("入住费用"),200);
	page3.m_list.SetColumnWidth(0, 100);
	page3.m_list.SetColumnWidth(1, 150);
	page3.m_list.SetColumnWidth(2, 100);
	page3.m_list.SetColumnWidth(3, 100);
	page3.m_list.SetColumnWidth(4, 100);
	page3.m_list.SetColumnWidth(5, 100);
	page3.m_list.SetColumnWidth(6, 100);




	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHotelManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHotelManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


