#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void Nhap(int A[], int &n);
void Xuat(int A[], int n);
void Quick_Sort(int A[], int left, int right);
void Start();

int main()
{
	Start();
	return 0;
}

void Start()
{
	int n,A[SIZE],left,right;
	Nhap(A,n);
	Xuat(A,n);
//	cout<<"Sap xep theo Quick Sort: "<<endl;
	printf("Sap xep theo Quick Sort: \n");
	Quick_Sort(A,0,n-1);
	Xuat(A,n);
}

void Quick_Sort(int A[], int left, int right)
{
	if(left >= right)
	{
		return ;
	}
	int val_mid=A[(left+right)/2];
	int i=left,j=right;
	do
	{
		while(A[i]<val_mid)
		{
			i++;
		}
		while(A[j]>val_mid)
		{
			j--;
		}
		if(i<=j)
		{
			int Temp=A[i];
			A[i]=A[j];
			A[j]=Temp;
			i++;
			j--;
		}
	}while(i<j);
	if(i<right)
	{
		Quick_Sort(A,i,right);
	}
	if(left<j)
	{
		Quick_Sort(A,left,j);
	}
}

void Xuat(int A[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
//		cout<<A[i]<<" ";
		printf("%d\t",A[i]);
	}
//	cout<<endl;
	printf("\n");
}

void Nhap(int A[], int &n)
{
//	cout<<"Nhap so luong phan tu: ";
	printf("Nhap so luong phan tu: ");
//	cin>>n;
	scanf("%d",&n);
//	cout<<"Nhap mang: "<<endl;
	printf("Nhap mang: \n");
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		A[i]=rand()%(100-1+1)+1;
	}
}
