// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "HotelManagementDlg.h"
#include "Login.h"

#include "resource.h"
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>

#include "FindPassword.h"
#include "CreateUser.h"

#include <WinSock2.h>
#include "winsock.h"
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")



// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialog)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
	, m_LoginUserNameEdit(_T(""))
	, m_LoginUserPasswordEdit(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LoginUserNameEdit, m_LoginUserNameEdit);
	DDX_Text(pDX, IDC_LoginUserPasswordEdit, m_LoginUserPasswordEdit);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDC_LoginCreateUserButton, &CLogin::OnBnClickedLogincreateuserbutton)
	ON_BN_CLICKED(IDC_LoginFindPasswirdButton, &CLogin::OnBnClickedLoginfindpasswirdbutton)
END_MESSAGE_MAP()


// CLogin 消息处理程序

void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
			MYSQL mysql;
			MYSQL_RES *result;
			MYSQL_ROW row;
			mysql_init(&mysql);
			std::string UserName("root");
			std::string PassWord("");
			std::string Database("hotelmanagement");
			std::string Table("usermanage");
			std::string loginName;
			loginName = CT2A(m_LoginUserNameEdit.GetBuffer()) ;
			

	
			mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);

			mysql_query(&mysql,"set names 'gbk'");

			std::string sql ="select userPassWord from usermanage where userName = '"+loginName+"';";
						if(0==mysql_query(&mysql,sql.c_str()))
			{
				//查询成功
				//一次性取得数据集
				result = mysql_store_result(&mysql);
				
				row=mysql_fetch_row(result);
				if(row!=NULL){
				CString passwordstr(row[0]);
				
				if(passwordstr == m_LoginUserPasswordEdit)
				{
					OnOK();
					CHotelManagementDlg dlg;
					INT_PTR nResponse = dlg.DoModal();
				}
				else
				{
					MessageBox("用户名或密码错误!");

				}}else
				{
					MessageBox("用户名错误!");
				}
			}
			else
			{
				MessageBox("数据库查询失败！");
			}


}

void CLogin::OnBnClickedLogincreateuserbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CCreateUser newUser;
	newUser.DoModal();

}

void CLogin::OnBnClickedLoginfindpasswirdbutton()
{
	// TODO: 在此添加控件通知处理程序代码
CFindPassWord findpassword;
findpassword.DoModal();
}
