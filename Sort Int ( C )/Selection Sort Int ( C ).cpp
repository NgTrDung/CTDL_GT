#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100


void Nhap(int A[], int &n);
void Xuat(int A[], int n);
void Selection_Sort(int A[], int n);
void Start();

int main()
{
	Start();
	return 0;
}

void Start()
{
	int n, A[SIZE];
	Nhap(A,n);
	Xuat(A,n);
//	cout<<"Sap xep theo Selection Sort: "<<endl;
	printf("Sap xep theo Selection Sort: \n");
	Selection_Sort(A,n);
	Xuat(A,n);
}

void Selection_Sort(int A[], int n)
{
	int min,i,j;
	for(i=0;i<n-1;i++)
	{
		min=i;	//gia su vi tri dau tien cua mang co gia tri nho nhat
		for(j=i+1;j<n;j++)	//vong lap tim gia tri nho nhat trong cac phan tu con lai
		{
			if(A[j] < A[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int Temp=A[i];
			A[i]=A[min];
			A[min]=Temp;
		}
	}
}

void Xuat(int A[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
//		cout<<A[i]<<"\t";
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
