// CreateUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "HotelManagementDlg.h"
#include "Login.h"
#include "resource.h"
#include "CreateUser.h"

#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "FindPassword.h"

#include <WinSock2.h>
#include "winsock.h"
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")

// CCreateUser �Ի���

IMPLEMENT_DYNAMIC(CCreateUser, CDialog)

CCreateUser::CCreateUser(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateUser::IDD, pParent)
	, m_CreateManagementPasswordEdit(_T(""))
	, m_CreateUserNameEdit(_T(""))
	, m_CreateUserPasswordEdit(_T(""))
	, m_CreateUserPassword2Edit(_T(""))
{

}

CCreateUser::~CCreateUser()
{
}

void CCreateUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CreateManagePasswordEdit, m_CreateManagementPasswordEdit);
	DDX_Text(pDX, IDC_CreateUserNameEdit, m_CreateUserNameEdit);
	DDX_Text(pDX, IDC_CreateUserPasswordEdit, m_CreateUserPasswordEdit);
	DDX_Text(pDX, IDC_CreateUserPassword2Edit, m_CreateUserPassword2Edit);
}


BEGIN_MESSAGE_MAP(CCreateUser, CDialog)
	ON_BN_CLICKED(IDOK, &CCreateUser::OnBnClickedOk)
END_MESSAGE_MAP()


// CCreateUser ��Ϣ�������

void CCreateUser::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	/*
	CString m_CreateManagementPasswordEdit;
	CString m_CreateUserNameEdit;
	CString m_CreateUserPasswordEdit;
	CString m_CreateUserPassword2Edit;
	*/

	if(m_CreateManagementPasswordEdit.IsEmpty()||m_CreateUserNameEdit.IsEmpty()|| m_CreateUserPasswordEdit.IsEmpty()||m_CreateUserPassword2Edit.IsEmpty())
	{
		MessageBox(_T("����д������Ϣ��"));
	}

	else{
	if(m_CreateManagementPasswordEdit == "000000")
	{
		if( m_CreateUserPasswordEdit ==  m_CreateUserPassword2Edit)
		{
			MYSQL mysql;
			mysql_init(&mysql);
			std::string UserName("root");
			std::string PassWord("");
			std::string Database("hotelmanagement");
			std::string Table("usermanage");
			std::string username;
			std::string userpassword;
			username = CT2A( m_CreateUserNameEdit.GetBuffer());
			userpassword = CT2A(m_CreateUserPasswordEdit.GetBuffer()) ;
			mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);

				mysql_query(&mysql,"set names 'gbk'");
			std::string sql2 = "insert into "+ Table + " values(\"" + username +"\"" + "," +  userpassword+")";


			if(0==mysql_query(&mysql, sql2.c_str()))
			{
				MessageBox("�½��û��ɹ���");
				OnOK();
			}
			else
			{
				MessageBox("�½��û�ʧ�ܣ�");
			}
		}
		else
		{
			MessageBox("�����������벻һ�£��������������룡");
		}
	}
	else
	{
		MessageBox("����Ա���벻��ȷ�����������룡");
	}


	}}
