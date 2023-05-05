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

struct LinkedStack
{
	Node *top;
};

void Initialize_Stack(LinkedStack &stack);
void Nhap_SanPham(SanPham &data);
void Xuat_SanPham(SanPham data);
Node *Create_Node(SanPham data);
bool Is_Empty_Stack(LinkedStack stack);
void Push(LinkedStack &stack, Node *data);
Node *Pop(LinkedStack &stack);
Node *Top(LinkedStack stack);
int SizeOfStack(LinkedStack stack);
bool Is_Full_Stack(LinkedStack stack);
void Print_Stack(LinkedStack stack);

int main()
{
	cout<<"Mac dinh ngan xep co toi da 100 stack!"<<endl;
	cout<<"\nKhoi tao hang doi rong: Completed!"<<endl;
	LinkedStack stack;
	Initialize_Stack(stack);
	cout<<"\nNhap so luong stack ban dau:  ";
	int n;
	cin>>n;
	cout<<"\nThuc hien them phan tu vao Stack bang Push:"<<endl;
	for(int i=0;i<n;i++)
	{
		SanPham dataSanPham;
		Nhap_SanPham(dataSanPham);
		Node *data = Create_Node(dataSanPham);
		Push(stack,data);
	}
	if(Is_Empty_Stack(stack)==true)
	{
		cout<<"\nNgan xep dang rong"<<endl;
	}
	if(Is_Empty_Stack(stack)==false)
	{
		cout<<"\nNgan xep khong rong"<<endl;
	}
	if(Is_Full_Stack(stack)==true)
	{
		cout<<"\nNgan xep dang bi day"<<endl;
	}
	if(Is_Full_Stack(stack)==false)
	{
		cout<<"\nNgan xep chua day"<<endl;
	}
	cout<<"\nThong tin trong ngan xep:  "<<endl;
	Print_Stack(stack);
	cout<<"\nThem 1 phan tu vao ngan xep:"<<endl;
	SanPham dataSanPham;
	Nhap_SanPham(dataSanPham);
	Node *data=Create_Node(dataSanPham);
	Push(stack,data);
	cout<<"\nThong tin trong ngan xep sau khi them phan tu moi la:"<<endl;
	Print_Stack(stack);
	cout<<"\nThong tin phan tu dau ngan xep:"<<endl;
	Node *pTemp = Top(stack);
	Xuat_SanPham(pTemp->data);
	cout<<"\nTrich huy phan tu dau ngan xep:  Task Completed!"<<endl;
	Node *pTemp2 = Pop(stack);
	cout<<"\nThong tin trong ngan xep hien tai:"<<endl;
	Print_Stack(stack);
	
	return 0;
}

void Initialize_Stack(LinkedStack &stack)
{
	stack.top=NULL;
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
		printf("Cap phat bo nho that bai!\n");
	}
	return pNode;	
}

bool Is_Empty_Stack(LinkedStack stack)
{
	if(stack.top == NULL)
	{
		return true;// ngan xep rong
	}
	return false;//ngan xep khong rong
}

void Push(LinkedStack &stack, Node *data)
{
	data->pNext=stack.top;
	stack.top=data;
}

Node *Pop(LinkedStack &stack)
{
	Node *pTemp=stack.top;
	//SanPham Temp = stack.top->data;
	stack.top = stack.top->pNext;
	pTemp->pNext=NULL;
	delete pTemp;
	return pTemp;
}

Node *Top(LinkedStack stack)
{
	Node *pTemp = stack.top;
	return pTemp;
}

int SizeOfStack(LinkedStack stack)
{
	Node *pTemp= stack.top;
	int nSize=0;
	while(pTemp!=NULL)
	{
		pTemp=pTemp->pNext;
		nSize++;
	}
	return nSize;
}

bool Is_Full_Stack(LinkedStack stack)
{
	int nSize= SizeOfStack(stack);
	if(nSize==100)
	{
		return true;//danh sach day
	}
	return false;
}

void Print_Stack(LinkedStack stack)
{
	Node *pTemp2=stack.top;
	while(pTemp2!=NULL)
	{
		Xuat_SanPham(pTemp2->data);
		pTemp2=pTemp2->pNext;
	}
}

