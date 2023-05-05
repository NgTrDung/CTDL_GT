#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void Nhap(int A[], int &n);
void Xuat(int A[], int n);
void Shaker_Sort(int A[], int n);
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
	printf("Sap xep theo Shaker Sort: \n");
	Shaker_Sort(M,n);
	Xuat(M,n);
}

void Shaker_Sort(int A[], int n)
{
	int left = 0,right = n - 1,k = 0,i;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
			{
				int Temp=A[i];
				A[i]=A[i+1];
				A[i+1]=Temp;
				k = i;
			}
		}
		right = k;
		for (i = right; i > left; i--)
		{
			if (A[i] < A[i - 1])
			{
				int Temp=A[i];
				A[i]=A[i-1];
				A[i-1]=Temp;
				k = i;
			}
		}
		left = k;
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
