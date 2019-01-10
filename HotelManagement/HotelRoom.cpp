// HotelRoom.cpp : 实现文件
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "HotelRoom.h"
#include <WinSock2.h>
#include "winsock.h"
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")


// HotelRoom 对话框

IMPLEMENT_DYNAMIC(HotelRoom, CDialog)

HotelRoom::HotelRoom(CWnd* pParent /*=NULL*/)
	: CDialog(HotelRoom::IDD, pParent)
{

}

HotelRoom::~HotelRoom()
{
}

void HotelRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
}


BEGIN_MESSAGE_MAP(HotelRoom, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &HotelRoom::OnBnClickedButton1)
END_MESSAGE_MAP()


// HotelRoom 消息处理程序

void HotelRoom::OnBnClickedButton1()
{
	
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_list.DeleteAllItems();
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	std::string Table("hotelroom");
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
				//处理获取的是价格的信息				
				KeyWordField ="Price";
				break;
			case 1:
				//处理获取的是空房的信息
				KeyWordField ="isEmpty";
				KeyWord="1";
				break;
			case 2:
				//处理获取的是类型的信息
				KeyWordField ="Type";
				break;		
			case 3:
				//处理的是位置的信息
				KeyWordField ="Position";		
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

	CString Price,Position,Type,IsEmpty; 
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
				 Price=CString(row[i]);
				 m_list.SetItemText(j,i,Price);
				} 
				else 
				if(i==1) 
				{ 
				 Position=CString(row[i]);
				 m_list.SetItemText(j,i,Position);
				} 
				else 
				if(i==2) 
				{ 
				 Type=CString(row[i]); 
				 m_list.SetItemText(j,i,Type);
				} 
				else 
				if(i==3) 
				{ 
				 IsEmpty=CString(row[i]);
				 m_list.SetItemText(j,i,IsEmpty);
				} 
			  } 
			  j++;
	  }
	 } 

	mysql_close(&mysql);
}
