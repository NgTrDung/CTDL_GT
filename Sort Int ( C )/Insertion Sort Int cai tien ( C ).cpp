#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void Nhap(int A[], int &n);
void Xuat(int A[], int n);
void Insertion_Sort_cai_tien(int A[], int n);
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
	printf("Sap xep theo Insertion Sort cai tien: \n");
	Insertion_Sort_cai_tien(M,n);
	Xuat(M,n);
}

void Insertion_Sort_cai_tien(int A[], int n)
{
	int l,m,r,i,j;
	int x;
	for(i=1;i<n;i++)
	{
		x=A[i];
		l=0;
		r=i-1;
		while(l<=r)
		{
			m=(l+r)/2;
			if(x<A[m])
			{
				r=m-1;
			}
			else if(x>A[m])
			{
				l=m+1;
			}
		}
		for(j=i-1;j>=l;j--)
		{
			A[j+1]=A[j];
		}
		A[l]=x;
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
