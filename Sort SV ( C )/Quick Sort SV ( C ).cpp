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
void Quick_Sort_SV(SinhVien A[], int left, int right);

int main()
{
	SinhVien A[100];
	int n;
	Nhap(A,n);
	Quick_Sort_SV(A,0,n-1);
	Xuat(A,n);
	return 0;
}

void Quick_Sort_SV(SinhVien A[], int left, int right)
{
	if(left >= right)
	{
		return ;
	}
	SinhVien val_mid=A[(left+right)/2];
	int i=left,j=right;
	do
	{
		while(A[i].DTB < val_mid.DTB || A[i].DTB == val_mid.DTB && ( A[i].MSSV < val_mid.MSSV ))
		{
			i++;
		}
		while(A[j].DTB > val_mid.DTB || A[j].DTB == val_mid.DTB && ( A[j].MSSV > val_mid.MSSV ))
		{
			j--;
		}
		if(i<=j)
		{
			SinhVien Temp=A[i];
			A[i]=A[j];
			A[j]=Temp;
			i++;
			j--;
		}
	}while(i<j);
	if(i<right)
	{
		Quick_Sort_SV(A,i,right);
	}
	if(left<j)
	{
		Quick_Sort_SV(A,left,j);
	}
}

void Xuat(SinhVien A[], int n)
{
	printf("\nSau khi sap xep bang Quick Sort: \n");
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
