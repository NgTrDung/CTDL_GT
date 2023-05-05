#include<stdio.h>
#include<iostream>

using namespace std;

struct SanPham
{
	char masanpham[20], tensanpham[100], nhasanxuat[100];
	float giatien;
};

struct Node
{
	SanPham data;
	Node *pNext;
};

struct LinkedQueue
{
	Node *pFront;
	Node *pRear;
};

void Initialize_Queue(LinkedQueue &queue);
void Nhap_SanPham(SanPham &data);
void Xuat_SanPham(SanPham data);
Node *Create_Node(SanPham data);
bool Is_Empty_Queue(LinkedQueue queue);
void EnQueue(LinkedQueue &queue, Node *data);
int SizeOfQueue(LinkedQueue queue);
bool Is_Full_Queue(LinkedQueue queue);
SanPham Front(LinkedQueue queue);
Node *DeQueue(LinkedQueue &queue);
void Print_Queue(LinkedQueue queue);

int main()
{
	cout<<"Mac dinh hang doi co toi da 100 phan tu!"<<endl;
	LinkedQueue queue;
	Initialize_Queue(queue);
	cout<<"\nNhap so phan tu ban dau trong hang doi:  ";
	int n;
	cin>>n;
	cout<<"\nThuc hien them phan tu vao Queue bang EnQueue:"<<endl;
	for(int i=0;i<n;i++)
	{
		SanPham dataSanPham;
		Nhap_SanPham(dataSanPham);
		Node *data = Create_Node(dataSanPham);
		EnQueue(queue,data);
	}
	if(Is_Empty_Queue(queue)==true)
	{
		cout<<"\nHang doi dang bi rong"<<endl;
	}
	else if(Is_Empty_Queue(queue)==false)
	{
		cout<<"\nHang doi dang khong bi rong"<<endl;
	}
	cout<<"\nThong tin cac phan tu trong hang doi hien tai:"<<endl;
	Print_Queue(queue);
	cout<<"\nLay thong tin phan tu dau hang doi hien tai:"<<endl;
	fflush(stdin);
	SanPham spTemp = Front(queue);
	Xuat_SanPham(spTemp);
	cout<<"\nThem 1 phan tu vao cuoi hang doi:"<<endl;
	SanPham dataSanPham;
	Nhap_SanPham(dataSanPham);
	Node *pTemp=Create_Node(dataSanPham);
	EnQueue(queue,pTemp);
	cout<<"\nThong tin cac phan tu trong hang doi hien tai:"<<endl;
	Print_Queue(queue);
	cout<<"\nLay phan tu o dau hang doi ra khoi hang doi: Task Completed!"<<endl;
	Node *pTemp2 = DeQueue(queue);
	fflush(stdin);
	
	
	return 0;
}

void Initialize_Queue(LinkedQueue &queue)
{
	queue.pFront = queue.pRear = NULL;
}

void Nhap_SanPham(SanPham &data)
{
	fflush(stdin);
	cout<<"\nNhap ma san pham:  ";
	gets(data.masanpham);
	fflush(stdin);
	cout<<"Nhap ten san pham:  ";
	gets(data.tensanpham);
	cout<<"Nhap gia tien:  ";
	cin>>data.giatien;
	cout<<"Nhap nha san xuat:  ";
	fflush(stdin);
	gets(data.nhasanxuat);
}

void Xuat_SanPham(SanPham data)
{
	cout<<"\nMa san pham:  "<<data.masanpham<<"     Ten San Pham:  "<<data.tensanpham<<"     Gia tien:  "<<data.giatien<<"     Nha san xuat:  "<<data.nhasanxuat<<endl;
}

Node *Create_Node(SanPham data)
{
	Node *pNode = new Node;
	if(pNode!=NULL)
	{
		pNode->data=data;
		pNode->pNext=NULL;
	}
	else
	{
		printf("\nCap phat bo nho that bai!\n");
	}
	return pNode;	
}

bool Is_Empty_Queue(LinkedQueue queue)
{
	if(queue.pFront == NULL)
	{
		return true;// ngan xep rong
	}
	return false;//ngan xep khong rong
}

void EnQueue(LinkedQueue &queue, Node *data)
{
	if(Is_Full_Queue(queue)==true)
	{
		cout<<"\nHang doi dang bi day, khong the EnQueue"<<endl;
		return;
	}
	if(Is_Empty_Queue(queue)==true)
	{
		queue.pFront=data;
		queue.pRear=data;
	}
	else if(Is_Empty_Queue(queue)==false)
	{
		queue.pRear->pNext=data;
		queue.pRear=data;
	}
}

int SizeOfQueue(LinkedQueue queue)
{
	Node *pTemp= queue.pFront;
	int nSize=0;
	while(pTemp!=NULL)
	{
		pTemp=pTemp->pNext;
		nSize++;
	}
	return nSize;
}

bool Is_Full_Queue(LinkedQueue queue)
{
	int nSize= SizeOfQueue(queue);
	if(nSize==100)
	{
		return true;//danh sach day
	}
	return false;
}

SanPham Front(LinkedQueue queue)
{
	SanPham spTemp=queue.pFront->data;
	return spTemp;
}

Node *DeQueue(LinkedQueue &queue)
{
	Node *pTemp = queue.pFront;
	if(pTemp==NULL)
	{
		cout<<"\nHang doi dang bi rong"<<endl;
	}
	else
	{
		cout<<"Thong tin phan tu dau hang doi:"<<endl;
		Xuat_SanPham(pTemp->data);
		if(queue.pFront = queue.pRear)
		{
			queue.pFront = queue.pRear = NULL;
		}
		else
		{
			queue.pFront = queue.pFront->pNext;
		}
		pTemp->pNext=NULL;
		delete pTemp;
	}
	return NULL;
}

void Print_Queue(LinkedQueue queue)
{
	Node *pTemp2=queue.pFront;
	while(pTemp2!=NULL)
	{
		Xuat_SanPham(pTemp2->data);
		pTemp2=pTemp2->pNext;
	}
}

