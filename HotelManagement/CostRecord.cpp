// CostRecord.cpp : 实现文件
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


// CostRecord 对话框

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


// CostRecord 消息处理程序

void CostRecord::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
		message = "请选择查找类型";
		MessageBox(message,"提示");
	}
	else
	{
		switch(nIndex){
			case 0:
				//处理获取的是客房位置的信息				
				KeyWordField ="RoomPosition";
				break;
			case 1:
				//处理获取的是客人电话的信息
				KeyWordField ="GuestPhone";
				break;
			case 2:
				//处理获取的是客人身份证的信息
				KeyWordField ="GuestID";
				break;		
			case 3:
				//处理的是客人姓名的信息
				KeyWordField ="GuestName";		
				break;
			default:CString message;
					message = "查找类型错误";
					MessageBox(message,"提示");
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
