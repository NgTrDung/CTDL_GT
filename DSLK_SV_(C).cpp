#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iomanip>
#define SIZE 100

using namespace std;

struct SinhVien
{
	char HOTEN[50];
	int MSSV;
	float DTB;
};

struct Node
{
	SinhVien data;
	Node *pNext;
};

struct SingleList 
{
	Node *pHead;
	Node *pTail;
};

void Initialize_List(SingleList &x)
{
	x.pHead=NULL;
}

int SizeOfList(SingleList list)
{
	Node *pTemp= list.pHead;
	int nSize=0;
	while(pTemp!=NULL)
	{
		pTemp=pTemp->pNext;
		nSize++;
	}
	return nSize;
}

bool IsFullList(SingleList list)
{
	int nSize= SizeOfList(list);
	if(nSize==100)
	{
		return true;//danh sach day
	}
	return false;
}

void Nhap_SV(SinhVien &x)
{
	fflush(stdin);
	cout<<"Ho va ten: ";
	gets(x.HOTEN);
	fflush(stdin);
	cout<<"MSSV: ";
	cin>>x.MSSV;
	fflush(stdin);
	cout<<"Diem trung binh: ";
	cin>>x.DTB;
}

Node *CreateNode(SinhVien x)
{
	Nhap_SV(x);
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=x;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Cap phat du lieu that bai!\n";
	}
	return pNode;
}

int IsEmptyList(SingleList list)
{
	if(list.pHead==NULL)
	{
		return 1;//rong
	}
	return 0;//khong rong
}

void Add_First(SingleList &x,Node *d)
{
	if(IsEmptyList(x)==1)//dsach rong
	{
		x.pHead=x.pTail=d;
	}
	else if(IsFullList(x)==true)
	{
		cout<<"Danh sach da day!\n";
	}
	else
	{
		d->pNext=x.pHead;
		x.pHead=d;
	}
}

void Add_Last(SingleList &x, Node *d)
{
	if(IsEmptyList(x)==1)//dsach rong
	{
		x.pHead=x.pTail=d;
	}
	else if(IsFullList(x)==true)
	{
		cout<<"Danh sach da day!\n";
	}
	else
	{
		x.pTail->pNext=d;
		x.pTail=d;
	}
}

void Remove_First(SingleList &x)
{
	if(IsEmptyList(x)==1)//dsach rong
	{
		cout<<"Danh sach lien ket dn dang bi rong!\n";
	}
	else
	{
		Node *pTemp=x.pHead;
		if(x.pHead==x.pTail)//dsach chi co 1 ptu
		{
			x.pHead=x.pTail=NULL;
		}
		else
		{
			x.pHead=x.pHead->pNext;
		}
		pTemp->pNext=NULL;
		delete pTemp;
	}
}

void Remove_Last(SingleList &x)
{
	if(IsEmptyList(x)==1)
	{
		cout<<"Danh sach lien ket don dang bi rong!\n";
	}
	else
	{
		Node *pTemp=x.pTail;
		if(x.pHead==x.pTail)//dsach chi co 1 ptu
		{
			x.pHead=x.pTail=NULL;
		}
		else
		{
			Node *pTemp2;
			for(pTemp2=x.pHead;pTemp2->pNext!=x.pTail;pTemp2=pTemp2->pNext)
			{
				
			}
			pTemp2->pNext=NULL;
			x.pTail=pTemp2;
		}
		delete pTemp;
	}
}

int Search_Node(SingleList x, SinhVien &d)
{
	Node *pTemp=x.pHead;
	cout<<"Nhap ten sinh vien muon tim: \n";
	fflush(stdin);
	cout<<"Ho va ten: ";
	gets(d.HOTEN);
	while(pTemp!=NULL)
	{
		if(stricmp(pTemp->data.HOTEN,d.HOTEN)==0)
		{
			return 1;//tim thay
		}
		pTemp=pTemp->pNext;
	}
	return 0;//khong tim thay
}

void Print_List(SingleList x)
{
	Node *pTemp=x.pHead;
	if(pTemp==NULL)
	{
		cout<<"Danh sach rong!\n";
	}
	else
	{
		while(pTemp!=NULL)
		{
			cout<<pTemp->data.HOTEN<<"     "<<pTemp->data.MSSV<<"     "<<pTemp->data.DTB<<"\n";
			pTemp=pTemp->pNext;
		}
	}
	cout<<"\n";
}

void Add_SinhVien(SingleList &list)
{
	cout<<"Nhap thong tin sinh vien muon them:  \n";
	SinhVien x;
	Node *pTemp=CreateNode(x);
	Add_Last(list,pTemp);
	cout<<"Danh sach sinh vien moi: \n";
	Print_List(list);
}

SingleList DSSV_DTB_Bigger_X(SingleList list, SinhVien &x)
{
	SingleList TempList;
	Initialize_List(TempList);
	cout<<"Nhap DTB ma ban muon so sanh:  ";
	cin>>x.DTB;
	Node *pTemp=list.pHead;
	while(pTemp!=NULL)
	{
		if(pTemp->data.DTB>=x.DTB)
		{
			Add_Last(TempList,pTemp);
		}
		pTemp=pTemp->pNext;
	}
	if(SizeOfList(TempList)==0)
	{
		cout<<"Trong danh sach khong co sinh vien nao DTB >= "<<x.DTB<<"\n";
	}
	return TempList;
}

SingleList Remove_DTB_Bigger_X(SingleList list, SinhVien &x)
{
	SingleList TempList;
	Initialize_List(TempList);
	cout<<"Nhap DTB ma ban muon so sanh:  ";
	cin>>x.DTB;
	Node *pTemp=list.pHead;
	while(pTemp!=NULL)
	{
		if(pTemp->data.DTB<x.DTB)
		{
			Add_Last(TempList,pTemp);
		}
		pTemp=pTemp->pNext;
	}
	if(SizeOfList(TempList)==0)
	{
		cout<<"Trong danh sach khong co sinh vien nao DTB < "<<x.DTB<<"\n";
	}
	return TempList;
}

float Number_DTB_MAX(SingleList list)
{
	Node *pTemp=list.pHead;
	float MAX=0;
	while(pTemp!=NULL)
	{
		if(pTemp->data.DTB>MAX)
		{
			MAX=pTemp->data.DTB;
		}
		pTemp=pTemp->pNext;
	}
	return MAX;
	
}

void Xuat_Number_DTB_MAX(SingleList list)
{
	float MAX = Number_DTB_MAX(list);
	Node *pTemp=list.pHead;
	int dem=0;
	while(pTemp!=NULL)
	{
		if(pTemp->data.DTB==MAX)
		{
			dem++;
		}
		pTemp=pTemp->pNext;
	}
	cout<<"Trong danh sach co "<<dem<<" sinh vien co DTB lon nhat\n";
}

void Nhap_DSSV(SingleList &list, int &n)
{
	cout<<"Nhap so luong sinh vien muon tao danh sach:  ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		SinhVien x;
		Node *pTemp=CreateNode(x);
		Add_Last(list,pTemp);
	}
}

int main()
{
	SingleList list;
	Initialize_List(list);
//	SinhVien x,y,z;
//	Node *pTemp1=CreateNode(x);
//	Add_First(list,pTemp1);
//	Node *pTemp2=CreateNode(y);
//	Add_Last(list,pTemp2);
//	Print_List(list);
//	int res = Search_Node(list,y);
//	if(res==0)
//	{
//		cout<<"co tim thay!\n";
//	}
//	Node *pTemp3=CreateNode(z);
//	Add_Last(list,pTemp3);
//	SinhVien sv;
//	SingleList list1 = DSSV_DTB_Bigger_X(list,sv);
//	Print_List(list1);
	int n;
	Nhap_DSSV(list,n);
	cout<<"Danh sach sinh vien hien tai: \n";
	Print_List(list);
	SinhVien x;
	int temp= Search_Node(list,x);
	if(temp==1)
	{
		cout<<"Khong tim thay!\n";
	}
	else
	{
		cout<<"Sinh vien nay co trong danh sach!\n";
	}
	Add_SinhVien(list);

	SinhVien y;
	SingleList list1 = DSSV_DTB_Bigger_X(list,y);
	cout<<"Danh sach sinh vien DTB >= "<<y.DTB<<" la: \n";
	Print_List(list1);
	SinhVien z;
	SingleList list2 = Remove_DTB_Bigger_X(list1,z);
	cout<<"Danh sach sinh vien sau khi xoa sinh vien co DTB >= "<<z.DTB<<" la: \n";
	Print_List(list2);
	Xuat_Number_DTB_MAX(list2);
	
	system("pause");
	return 0;
}
