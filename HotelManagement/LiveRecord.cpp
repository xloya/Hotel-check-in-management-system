// LiveRecord.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HotelManagement.h"
#include "LiveRecord.h"
#include <WinSock2.h>
#include "winsock.h"
#include "mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")

// LiveRecord �Ի���

IMPLEMENT_DYNAMIC(LiveRecord, CDialog)

LiveRecord::LiveRecord(CWnd* pParent /*=NULL*/)
	: CDialog(LiveRecord::IDD, pParent)
{

}

LiveRecord::~LiveRecord()
{
}

void LiveRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
}


BEGIN_MESSAGE_MAP(LiveRecord, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &LiveRecord::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LiveRecord::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &LiveRecord::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &LiveRecord::OnBnClickedButton3)
END_MESSAGE_MAP()


// LiveRecord ��Ϣ�������

void LiveRecord::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_list.DeleteAllItems();//���
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	std::string Table("liverecord");
	std::string KeyWordField;
	std::string KeyWord;
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);


	int nIndex = m_ComboBox.GetCurSel();
	UpdateData(true);
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
				//�����ȡ���ǿ��˵绰����Ϣ				
				KeyWordField ="GuestPhone";
				break;
			case 1:
				//�����ȡ���ǿ������֤����Ϣ
				KeyWordField ="GuestID";
				break;
			case 2:
				//�����ȡ���ǿ�����������Ϣ
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
	CString guestname,guestid,guestphone,roomposition,type,liveintime,livedays; 
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
				 guestname=CString(row[i]);
				 m_list.SetItemText(j,i,guestname);
				} 
				else if(i==1) 
				{ 
				 guestid=CString(row[i]);
				 m_list.SetItemText(j,i,guestid);
				} 
				else if(i==2) 
				{ 
				 guestphone=CString(row[i]); 
				 m_list.SetItemText(j,i,guestphone);
				} 
				else if(i==3) 
				{ 
				 roomposition=CString(row[i]);
				 m_list.SetItemText(j,i,roomposition);
				} 
				else if(i==4) 
				{ 
				 type=CString(row[i]);
				 m_list.SetItemText(j,i,type);
				} 
				else if(i==5) 
				{ 
				 liveintime=CString(row[i]);
				 m_list.SetItemText(j,i,liveintime);
				} 
				else if(i==6) 
				{ 
				 livedays=CString(row[i]);
				 m_list.SetItemText(j,i,livedays);
				} 
			  } 
			  j++;
	  }
	 } 


	mysql_close(&mysql);
}

void LiveRecord::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);

	CString guestname;
	GetDlgItemText(IDC_GUESTNAME,guestname);
	
	CString guestid;
	GetDlgItemText(IDC_GUESTID,guestid);
	
	CString guestphone;
	GetDlgItemText(IDC_GUESTPHONE,guestphone);
	
	CString type;
	GetDlgItemText(IDC_TYPE,type);
	
	CString position;
	GetDlgItemText(IDC_POSITION,position);
	
	CString livedays;
	GetDlgItemText(IDC_LIVEDAYS,livedays);

	CString liveintime; //��ȡϵͳʱ��
	CTime tm;
	tm=CTime::GetCurrentTime();
	liveintime=tm.Format("%Y-%m-%d");

	if(guestname.IsEmpty()||guestid.IsEmpty()||guestphone.IsEmpty()||type.IsEmpty()||position.IsEmpty()||livedays.IsEmpty())
	{
		CString   sTemp;
		sTemp= "��������д��Ϣ!";
		MessageBox(sTemp,"��ʾ");  		
	}
	else
	{
		mysql_query(&mysql,"set names 'gbk'");

		char *guf=new char[200];
		sprintf(guf,"SELECT * FROM hotelroom WHERE Position='%s'", position);
		MYSQL_RES *result; 
		MYSQL_ROW sql_row; 
		int res=mysql_query(&mysql, guf);
		if(!res)
		{
			result=mysql_store_result(&mysql);
			if((sql_row = mysql_fetch_row(result)) != NULL)
			{
				if(atoi(sql_row[3])==1)
				{
					char *def=new char[200];
					sprintf(def,"UPDATE hotelroom SET isEmpty='0' WHERE Position='%s'", position); 
					mysql_query(&mysql, def);

					char *buf = new char[200]; 
					sprintf(buf,"INSERT INTO liverecord(GuestName,GuestID,GuestPhone,RoomPosition,Type,LiveInTime,LiveDays) VALUES('%s','%s','%s','%s','%s','%s','%s')",guestname,guestid,guestphone,position,type,liveintime,livedays);  

					if(!mysql_query(&mysql, buf)) 
					{ 
						CString   sTemp;
						sTemp= "��¼�ɹ�!";
						MessageBox(sTemp,"��ʾ");
						GetDlgItem(IDC_GUESTNAME)->SetWindowText(_T(""));
						GetDlgItem(IDC_GUESTID)->SetWindowText(_T(""));
						GetDlgItem(IDC_GUESTPHONE)->SetWindowText(_T(""));
						GetDlgItem(IDC_TYPE)->SetWindowText(_T(""));
						GetDlgItem(IDC_POSITION)->SetWindowText(_T(""));
						GetDlgItem(IDC_LIVEDAYS)->SetWindowText(_T(""));
					} 
					else 
					{ 
							CString   sTemp;
							sTemp= "��¼ʧ��!";
							MessageBox(sTemp,"��ʾ");  
					}
				}
				else
				{
					CString   sTemp;
					sTemp= "������ס��!";
					MessageBox(sTemp,"��ʾ");  
				}
			}
			else
			{
				CString   sTemp;
				sTemp= "��ѯʧ��!";
				MessageBox(sTemp,"��ʾ"); 
			}

		}
		else
		{
			CString   sTemp;
			sTemp= "��ѯʧ��!";
			MessageBox(sTemp,"��ʾ");  
		}
	}
	
	mysql_close(&mysql);
}

void LiveRecord::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);

	CString guestid;
	GetDlgItemText(IDC_GUESTID,guestid);

	CString livedays;
	GetDlgItemText(IDC_LIVEDAYS,livedays);

	if(guestid.IsEmpty()||livedays.IsEmpty())
	{
		CString   sTemp;
		sTemp= "��������д�û����֤����ס����!";
		MessageBox(sTemp,"��ʾ"); 
	}
	else
	{
		mysql_query(&mysql,"set names 'gbk'");
		char *guf=new char[200];
		sprintf(guf,"SELECT * FROM liverecord WHERE GuestID='%s'", guestid);
		MYSQL_RES *result; 
		MYSQL_ROW sql_row; 
		int res=mysql_query(&mysql, guf);
		if(!res)
		{
			result=mysql_store_result(&mysql);
			if((sql_row = mysql_fetch_row(result)) != NULL)
			{
				char *def=new char[200];
				sprintf(def,"UPDATE liverecord SET LiveDays='%s' WHERE GuestID='%s'", livedays,guestid);
				int result=mysql_query(&mysql, def);
				if(!result) 
				{ 
					CString   sTemp;
					sTemp= "�޸ĳɹ�!";
					MessageBox(sTemp,"��ʾ");
					GetDlgItem(IDC_GUESTID)->SetWindowText(_T(""));
					GetDlgItem(IDC_LIVEDAYS)->SetWindowText(_T(""));
				} 
				else 
				{ 
					CString   sTemp;
					sTemp= "�޸�ʧ��!";
					MessageBox(sTemp,"��ʾ");  
				}
			}
			else
			{
					CString   sTemp;
					sTemp= "���˲�����!";
					MessageBox(sTemp,"��ʾ");  
			}

		}
		else
		{
			CString   sTemp;
			sTemp= "��ѯ����ʧ��!";
			MessageBox(sTemp,"��ʾ");  
		}

	}
	mysql_close(&mysql);
}

void LiveRecord::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MYSQL mysql;
	mysql_init(&mysql);
	std::string UserName("root");
	std::string PassWord("");
	std::string Database("hotelmanagement");
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);

	CString guestid;
	GetDlgItemText(IDC_GUESTID,guestid);

	CString position;
	GetDlgItemText(IDC_POSITION,position);

	CString liveouttime; //��ȡϵͳʱ��
	CTime tm;
	tm=CTime::GetCurrentTime();
	liveouttime=tm.Format("%Y-%m-%d");

	CString Guestname,Guestphone,Liveintime;
	int Livedays,Price;

	if(guestid.IsEmpty()||position.IsEmpty())
	{
		CString   sTemp;
		sTemp= "��������д�û����֤�ͷ���λ��!";
		MessageBox(sTemp,"��ʾ"); 
	}
	else
	{
		mysql_query(&mysql,"set names 'gbk'");
		MYSQL_RES *result;
		MYSQL_ROW row;
		char *guf=new char[200];
		sprintf(guf,"SELECT * FROM hotelroom WHERE Position='%s'", position);  //��ȡ�۸�
		int res=mysql_query(&mysql, guf);
		if(!res)
		{
			result=mysql_store_result(&mysql);
			if((row = mysql_fetch_row(result)) != NULL)
			{
				Price=atoi(row[1]);
				MYSQL_RES *result1;
				MYSQL_ROW row1;
				char *buf=new char[200];
				sprintf(buf,"SELECT * FROM liverecord WHERE GuestID='%s'", guestid);		//��ȡ���˼�¼
				int res1=mysql_query(&mysql, buf);
				if(!res1)
				{
					result1=mysql_store_result(&mysql);
					while((row1 = mysql_fetch_row(result1)) != NULL) 
					{ 
										
						for(int i=0; i<mysql_num_fields(result1); i++) 
						{ 
							if(i==0) 
							{ 
								Guestname=CString(row1[i]);
							} 
							else if(i==2) 
							{ 
								Guestphone=CString(row1[i]);
							} 
							else if(i==5) 
							{ 
								Liveintime=CString(row1[i]);
							} 
							else if(i==6) 
							{ 
								Livedays=atoi(row1[i]);
							} 
						} 
					}

					char *def=new char[200];		//���¿ͷ���Ϣ
					sprintf(def,"UPDATE hotelroom SET isEmpty='1' WHERE Position='%s'", position);	
					if(!mysql_query(&mysql, def)) 
					{ 
						int totalcost=Livedays*Price;	//������Ϣ
						char *buff = new char[200]; 
						sprintf(buff,"INSERT INTO costtable(GuestName, GuestID, GuestPhone, RoomPosition, LiveInTime, LiveOutTime,TotalCost) VALUES('%s', '%s', '%s','%s', '%s', '%s', '%d')",Guestname, guestid, Guestphone, position, Liveintime, liveouttime,totalcost);  
							  
						if(!mysql_query(&mysql, buff)) 
						{ 
							char *deff = new char[200]; 
							sprintf(deff,"DELETE FROM liverecord WHERE GuestID='%s'", guestid); 
  
							if(!mysql_query(&mysql, deff)) 
							{ 
								CString   sTemp;
								sTemp= "�˷��ɹ�";
								MessageBox(sTemp,"��ʾ"); 
							} 
							else 
							{ 
								CString   sTemp;
								sTemp= "ɾ��ʧ��";
								MessageBox(sTemp,"��ʾ"); 
							} 

						} 
					    else 
						{ 
							CString   sTemp;
							sTemp= "����ʧ��";
							MessageBox(sTemp,"��ʾ"); 
						} 
					} 
					else 
					{ 
						CString   sTemp;
						sTemp= "����ʧ��";
						MessageBox(sTemp,"��ʾ"); 
					} 

				}
				else
				{
					CString   sTemp;
				    sTemp= "��ȡ���˼�¼ʧ��!";
				    MessageBox(sTemp,"��ʾ");  
				}
			}
			else
			{
				CString   sTemp;
				sTemp= "���ؽ��ʧ��!";
				MessageBox(sTemp,"��ʾ");  
			}
		}
		else
		{
			CString   sTemp;
			sTemp= "�ͷ���¼������!";
			MessageBox(sTemp,"��ʾ");  
		}
	
			
	}
}
