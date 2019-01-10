// Login.cpp : ʵ���ļ�
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



// CLogin �Ի���

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


// CLogin ��Ϣ�������

void CLogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
				//��ѯ�ɹ�
				//һ����ȡ�����ݼ�
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
					MessageBox("�û������������!");

				}}else
				{
					MessageBox("�û�������!");
				}
			}
			else
			{
				MessageBox("���ݿ��ѯʧ�ܣ�");
			}


}

void CLogin::OnBnClickedLogincreateuserbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCreateUser newUser;
	newUser.DoModal();

}

void CLogin::OnBnClickedLoginfindpasswirdbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
CFindPassWord findpassword;
findpassword.DoModal();
}
