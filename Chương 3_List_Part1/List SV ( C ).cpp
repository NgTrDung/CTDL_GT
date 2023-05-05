#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iomanip>
#define SIZE 100

using namespace std;

struct SinhVien
{
	char HOTEN[50];
	int MSSV;
	float DTB;
};

struct LIST
{
	SinhVien A[SIZE];
	int n;
};

void Initialize_List(LIST &x)
{
	x.n=0;
}

bool Empty_List(LIST x)
{
	if(x.n==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Is_Full_List(LIST x)
{
	if(x.n==SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Add_Last(LIST &x, SinhVien y)
{
	if(Is_Full_List(x)==true)
	{
		cout<<"The List is fulled!"<<endl;
	}
	else
	{
		x.n++;
		x.A[x.n-1]=y;
	}
}

void Nhap_SV(SinhVien &x)
{
	fflush(stdin);
	cout<<"Ho va ten: ";
	gets(x.HOTEN);
	fflush(stdin);
	cout<<"MSSV: ";
	cin>>x.MSSV;
	fflush(stdin);
	cout<<"Diem trung binh: ";
	cin>>x.DTB;
}

void Nhap_Mang_List(LIST &x, int &k)
{
	cout<<"Nhap so luong sinh vien ban dau trong danh sach:  ";
	cin>>k;
	x.n=k;
	cout<<"Nhap sinh vien: \n";
	for(int i=0;i<x.n;i++)
	{
		Nhap_SV(x.A[i]);	
		
	}	
}

void Xuat_SV(SinhVien x)
{
	cout<<"Ho va ten: "<<x.HOTEN<<"     MSSV: "<<x.MSSV<<"     DTB: "<<fixed<<setprecision(2)<<x.DTB<<"\n";
}

void Xuat_Mang_List(LIST x)
{
	cout<<"\nDanh sach sinh vien hien co: \n";
	for(int i=0;i<x.n;i++)
	{
		Xuat_SV(x.A[i]);
	}
	cout<<"\n";
}

void DoSort(LIST &x)
{
	int left = 0,right = x.n - 1,k = 0,i;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (x.A[i].DTB > x.A[i + 1].DTB || x.A[i].DTB == x.A[i+1].DTB && ( x.A[i].MSSV > x.A[i+1].MSSV ))
			{
				SinhVien Temp=x.A[i];
				x.A[i]=x.A[i+1];
				x.A[i+1]=Temp;
				k = i;
			}
		}
		right = k;
		for (i = right; i > left; i--)
		{
			if (x.A[i].DTB < x.A[i - 1].DTB || x.A[i].DTB == x.A[i-1].DTB && ( x.A[i].MSSV < x.A[i-1].MSSV ))
			{
				SinhVien Temp=x.A[i];
				x.A[i]=x.A[i-1];
				x.A[i-1]=Temp;
				k = i;
			}
		}
		left = k;
	}
}

LIST Them_Sinh_Vien(LIST &x)
{
	LIST DSSVmoi;
	if(Is_Full_List(x)==true)
	{
		cout<<"Danh sach da day, khong the them sinh vien!\n";
		return DSSVmoi=x;
	}
	else
	{
		cout<<"Nhap thong tin sinh vien ma ban muon them vao danh sach: \n";
		SinhVien y;
		Nhap_SV(y);
		Add_Last(x,y);
		DoSort(x);
		return DSSVmoi=x;
	}
}

LIST DTB_Lon_Hon_Bang_X(LIST x, float &k)
{
	LIST Temp_DTB_Bigger;
	Initialize_List(Temp_DTB_Bigger);
	cout<<"Nhap diem trung binh ma ban muon so sanh: ";
	cin>>k;
	for(int i=0;i<x.n;i++)
	{
		if(x.A[i].DTB>=k)
		{
			Add_Last(Temp_DTB_Bigger,x.A[i]);
		}
	}
	if(Temp_DTB_Bigger.n==0)
	{
		cout<<"Trong danh sach khong co sinh vien nao co diem trung binh lon hon "<<k<<"\n";
	}
	return Temp_DTB_Bigger;
	
}

LIST Remove_Temp_DTB_Bigger(LIST x, float &k)
{
	LIST Temp_DTB_Smaller;
	Initialize_List(Temp_DTB_Smaller);
	cout<<"Nhap diem trung binh ma ban muon so sanh: ";
	cin>>k;
	for(int i=0;i<x.n;i++)
	{
		if(x.A[i].DTB<k)
		{
			Add_Last(Temp_DTB_Smaller,x.A[i]);
		}
	}
	if(Temp_DTB_Smaller.n==0)
	{
		cout<<"Trong danh sach khong co sinh vien nao co diem trung binh nho hon "<<k<<"\n";
	}
	return Temp_DTB_Smaller;
}

void Num_SV_DTB_Max(LIST x)
{
	SinhVien MAX=x.A[0];
	for(int i=0;i<x.n;i++)
	{
		if(x.A[i].DTB>MAX.DTB)
		{
			MAX=x.A[i];
		}
	}
	int dem=0;
	for(int i=0;i<x.n;i++)
	{
		if(x.A[i].DTB == MAX.DTB)
		{
			dem++;
		}
	}
	cout<<"Trong danh sach co "<<dem<<" sinh vien co diem trung binh cao nhat la "<<fixed<<setprecision(2)<<MAX.DTB<<"\t";
	
}

int main()
{
	LIST sv;
	Initialize_List(sv);
	int k;
	Nhap_Mang_List(sv,k);
	DoSort(sv);
	Xuat_Mang_List(sv);
	cout<<"\n";
	
	cout<<"a) Them sinh vien moi vao cuoi danh sach: \n";
	LIST DSSVmoi=Them_Sinh_Vien(sv);
	Xuat_Mang_List(DSSVmoi);
	
	cout<<"b) Danh sach sinh vien co DTB >= x\n";
	float e;
	LIST DSSV_DTB_Bigger = DTB_Lon_Hon_Bang_X(DSSVmoi,e);
	Xuat_Mang_List(DSSV_DTB_Bigger);
	
	cout<<"c) Xoa sinh vien co DTB >= x\n";
	float f;
	LIST Remove_DSSV_DTB_Bigger = Remove_Temp_DTB_Bigger(DSSV_DTB_Bigger,f);
	Xuat_Mang_List(Remove_DSSV_DTB_Bigger);
	
	cout<<"d) So luong sinh vien co diem trung binh cao nhat:\n";
	Num_SV_DTB_Max(Remove_DSSV_DTB_Bigger);
	
	system("pause");
	return 0;
}
