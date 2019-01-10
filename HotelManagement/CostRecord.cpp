// CostRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "CostRecord.h"
#include <WinSock2.h>
#include "winsock.h"
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")


// CostRecord �Ի���

IMPLEMENT_DYNAMIC(CostRecord, CDialog)

CostRecord::CostRecord(CWnd* pParent /*=NULL*/)
	: CDialog(CostRecord::IDD, pParent)
{

}

CostRecord::~CostRecord()
{
}

void CostRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
}


BEGIN_MESSAGE_MAP(CostRecord, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CostRecord::OnBnClickedButton1)
END_MESSAGE_MAP()


// CostRecord ��Ϣ�������

void CostRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_list.DeleteAllItems();
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	std::string Table("costtable");
	std::string KeyWordField;
	std::string KeyWord;
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);


	int nIndex = m_ComboBox.GetCurSel();

	CString editStr;
	GetDlgItemText(IDC_EDIT1,editStr);
	KeyWord = CT2A(editStr.GetBuffer());

	if(nIndex == -1){
		CString message;
		message = "��ѡ���������";
		MessageBox(message,"��ʾ");
	}
	else
	{
		switch(nIndex){
			case 0:
				//�����ȡ���ǿͷ�λ�õ���Ϣ				
				KeyWordField ="RoomPosition";
				break;
			case 1:
				//�����ȡ���ǿ��˵绰����Ϣ
				KeyWordField ="GuestPhone";
				break;
			case 2:
				//�����ȡ���ǿ������֤����Ϣ
				KeyWordField ="GuestID";
				break;		
			case 3:
				//������ǿ�����������Ϣ
				KeyWordField ="GuestName";		
				break;
			default:CString message;
					message = "�������ʹ���";
					MessageBox(message,"��ʾ");
					break;
		}
	}

   	std::string sql = "select * from " +Table + " where " + KeyWordField + " like " + "\"%" + KeyWord +"%\"";
	
	MYSQL_RES *result;
	MYSQL_ROW row;
	CString sql2(sql.c_str());

	mysql_query(&mysql,"set names 'gbk'");

	CString guestName,guestID,guestPhone,roomPosition,liveintime,liveouttime,totalcost; 
	int j=0;
	int res=mysql_query(&mysql, sql2); 
	 if(!res) 
	 { 
	  result=mysql_store_result(&mysql); 
	    
	  while((row = mysql_fetch_row(result)) != NULL) 
	  { 
			
			  m_list.InsertItem(j,"");
			  for(int i=0; i<mysql_num_fields(result); i++) 
		      { 
				if(i==0) 
				{ 
				 guestName=CString(row[i]);
				 m_list.SetItemText(j,i,guestName);
				} 
				else 
				if(i==1) 
				{ 
				 guestID=CString(row[i]);
				 m_list.SetItemText(j,i,guestID);
				} 
				else 
				if(i==2) 
				{ 
				 guestPhone=CString(row[i]); 
				 m_list.SetItemText(j,i,guestPhone);
				} 
				else 
				if(i==3) 
				{ 
				 roomPosition=CString(row[i]);
				 m_list.SetItemText(j,i,roomPosition);
				} 
				else 
				if(i==4) 
				{ 
				 liveintime=CString(row[i]);
				 m_list.SetItemText(j,i,liveintime);
				} 
				else 
				if(i==5) 
				{ 
				 liveouttime=CString(row[i]);
				 m_list.SetItemText(j,i,liveouttime);
				} 
				else 
				if(i==6) 
				{ 
				 totalcost=CString(row[i]);
				 m_list.SetItemText(j,i,totalcost);
				} 
			  } 
			  j++;
	  }
	 } 

	mysql_close(&mysql);
}
