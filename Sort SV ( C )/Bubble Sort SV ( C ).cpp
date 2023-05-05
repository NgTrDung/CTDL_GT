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
void Bubble_Sort_SV(SinhVien A[], int n);

int main()
{
	SinhVien A[100];
	int n;
	Nhap(A,n);
	Bubble_Sort_SV(A,n);
	Xuat(A,n);
	return 0;
}

void Bubble_Sort_SV(SinhVien A[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(A[j].DTB < A[j-1].DTB || ( A[j].DTB == A[j-1].DTB && A[j].MSSV < A[j-1].MSSV ))
			{
				SinhVien Temp=A[j];
				A[j]=A[j-1];
				A[j-1]=Temp;
			}
		}
	}
}

void Xuat(SinhVien A[], int n)
{
	printf("\nSau khi sap xep bang Bubble Sort: \n");
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
