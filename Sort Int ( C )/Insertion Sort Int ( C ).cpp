#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100


void Nhap(int A[], int &n);
void Xuat(int A[], int n);
void Insertion_Sort(int A[], int n);
void Start();

int main()
{
	Start();
	return 0;
}

void Start()
{
	int n,M[SIZE];
	Nhap(M,n);
	Xuat(M,n);
//	cout<<"Sap xep theo Insertion Sort: "<<endl;
	printf("Sap xep theo Insertion Sort: \n");
	Insertion_Sort(M,n);
	Xuat(M,n);
}

void Insertion_Sort(int A[], int n)
{
	int x,i,pos=0;
	for(i=1;i<n;i++)
	{
		x=A[i];
		for(pos=i;(pos>0) && (A[pos-1]>x);pos--)
		{
			A[pos]=A[pos-1];
		}
		A[pos]=x;
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
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=rand()%(100-1+1)+1;
	}
}
