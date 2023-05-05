#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>

struct SinhVien
{
	char HOTEN[50];
	float DTB;
	int MSSV;
};

void NhapSV(SinhVien &x);
void XuatSV(SinhVien x);
void Nhap(SinhVien A[], int &n);
void Xuat(SinhVien A[], int n);
void Insertion_Sort_SV_cai_tien(SinhVien A[], int n);

int main()
{
	SinhVien A[100];
	int n;
	Nhap(A,n);
	Insertion_Sort_SV_cai_tien(A,n);
	Xuat(A,n);
	return 0;
}

void Insertion_Sort_SV_cai_tien(SinhVien A[], int n)
{
	int l,m,r,i,j;
	SinhVien x;
	for(i=1;i<n;i++)
	{
		x=A[i];
		l=0;
		r=i-1;
		while(l<=r)
		{
			m=(l+r)/2;
			if(x.DTB < A[m].DTB || ( x.DTB == A[m].DTB && x.MSSV < A[m].MSSV ))
			{
				r=m-1;
			}
			else if(x.DTB > A[m].DTB || ( x.DTB == A[m].DTB && x.MSSV > A[m].MSSV ))
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

void Xuat(SinhVien A[], int n)
{
	printf("\nSau khi sap xep bang Insertion Sort cai tien: \n");
	int i;
	for(i=0;i<n;i++)
	{
		XuatSV(A[i]);
	}
}

void Nhap(SinhVien A[], int &n)
{
	printf("Nhap so luong Sinh Vien can sap xep: ");
	scanf("%d",&n);
	printf("\nNhap mang Sinh Vien: \n");
	int i;
	for(i=0;i<n;i++)
	{
		NhapSV(A[i]);
	}
}

void XuatSV(SinhVien x)
{
	printf("Ho va Ten: %s \t MSSV: %d \t Diem trung binh: %0.2f \n",x.HOTEN,x.MSSV,x.DTB);
}

void NhapSV(SinhVien &x)
{
	fflush(stdin);
	printf("Nhap Ho va Ten: ");
	gets(x.HOTEN);
	fflush(stdin);
	printf("Nhap MSSV: ");
	scanf("%d",&x.MSSV);
	printf("Nhap Diem trung binh: ");
	scanf("%f",&x.DTB);
}
