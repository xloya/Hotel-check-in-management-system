// FindPassWord.cpp : 实现文件
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "FindPassWord.h"

#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>

#include <WinSock2.h>
#include "winsock.h"
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")
// CFindPassWord 对话框

IMPLEMENT_DYNAMIC(CFindPassWord, CDialog)

CFindPassWord::CFindPassWord(CWnd* pParent /*=NULL*/)
	: CDialog(CFindPassWord::IDD, pParent)
	, m_FindManagePasswordEdit(_T(""))
	, m_FindUserNameEdit(_T(""))
	, m_FindUserPassword2Edit(_T(""))
	, m_FindUserPasswordEdit1(_T(""))
{

}

CFindPassWord::~CFindPassWord()
{
}

void CFindPassWord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FindManagePasswordEdit, m_FindManagePasswordEdit);
	DDX_Text(pDX, IDC_FindUserNameEdit, m_FindUserNameEdit);
	DDX_Control(pDX, IDC_FindUserPasswordEdit, m_FindUserPasswordEdit);
	DDX_Text(pDX, IDC_FindUserPassword2Edit, m_FindUserPassword2Edit);
	DDX_Text(pDX, IDC_FindUserPasswordEdit, m_FindUserPasswordEdit1);
}


BEGIN_MESSAGE_MAP(CFindPassWord, CDialog)
	ON_BN_CLICKED(IDOK, &CFindPassWord::OnBnClickedOk)
END_MESSAGE_MAP()


// CFindPassWord 消息处理程序

void CFindPassWord::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	std::string Table("usermanage");

	if(m_FindManagePasswordEdit.IsEmpty()||m_FindUserPassword2Edit.IsEmpty()||m_FindUserPasswordEdit1.IsEmpty())
				{
					CString   sTemp;
					sTemp= "请填写完整的信息!";
					MessageBox(sTemp,"提示"); 
				}

	else{
	if(m_FindManagePasswordEdit == "000000")
	{
		if( m_FindUserPasswordEdit1 ==  m_FindUserPassword2Edit)
		{

			CString username;
			GetDlgItemText(IDC_FindUserNameEdit,username);

			CString userpassword;
			GetDlgItemText(IDC_FindUserPasswordEdit,userpassword);

			mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
			mysql_query(&mysql,"set names 'gbk'");


			/*
			CString livedays;
	GetDlgItemText(IDC_LIVEDAYS,livedays);

	if(guestid.IsEmpty()||livedays.IsEmpty())
	{
		CString   sTemp;
		sTemp= "请完整填写用户身份证和入住天数!";
		MessageBox(sTemp,"提示"); 
	}
			*/

			
			
			char *def=new char[200];
			sprintf(def,"UPDATE usermanage SET userPassWord = '%s' WHERE userName='%s'", userpassword,username);
			if(!mysql_query(&mysql, def))
			{
					MessageBox("修改密码成功");
					OnOK();
			}
			else
			{
				MessageBox("修改密码失败！");
			}
		}
		else
		{
			MessageBox("两次输入密码不一致，请重新输入密码！");
		}
	}
	else
	{
		MessageBox("管理员密码不正确，请重新输入！");
	}
	}
	mysql_close(&mysql);
}
