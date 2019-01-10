// FindPassWord.cpp : ʵ���ļ�
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
// CFindPassWord �Ի���

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


// CFindPassWord ��Ϣ�������

void CFindPassWord::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
					sTemp= "����д��������Ϣ!";
					MessageBox(sTemp,"��ʾ"); 
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
		sTemp= "��������д�û����֤����ס����!";
		MessageBox(sTemp,"��ʾ"); 
	}
			*/

			
			
			char *def=new char[200];
			sprintf(def,"UPDATE usermanage SET userPassWord = '%s' WHERE userName='%s'", userpassword,username);
			if(!mysql_query(&mysql, def))
			{
					MessageBox("�޸�����ɹ�");
					OnOK();
			}
			else
			{
				MessageBox("�޸�����ʧ�ܣ�");
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
	}
	mysql_close(&mysql);
}
