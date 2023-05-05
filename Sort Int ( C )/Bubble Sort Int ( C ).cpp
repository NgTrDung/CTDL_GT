#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void NhapMang(int A[], int &n);
void XuatMang(int A[], int n);
void BubbleSort(int A[], int n);
void Start();

int main()
{
	Start();
	return 0;
}

void Start()
{
	int n,A[100];
	NhapMang(A,n);
	XuatMang(A,n);
	BubbleSort(A,n);
//	cout<<"Sau sap xep: "<<endl;
	printf("Sap xep bang Bubble Sort: \n");
	XuatMang(A,n);
}

void BubbleSort(int A[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(A[j]<A[j-1])
			{
				int Temp=A[j];
				A[j]=A[j-1];
				A[j-1]=Temp;
			}
		}
	}	
}

void XuatMang(int A[], int n)
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

void NhapMang(int A[], int &n)
{
//	cout<<"Nhap so luong phan tu trong mang: ";
	printf("Nhap so luong phan tu trong mang: ");
//	cin>>n;
	scanf("%d",&n);
//	cout<<"Nhap mang: ";
	printf("Nhap mang: \n");
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=rand()%(100-1+1)+1;		
	}
}
