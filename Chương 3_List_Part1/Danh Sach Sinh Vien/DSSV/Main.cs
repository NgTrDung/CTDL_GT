using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DSSV
{
    class Program
    {
        public static void Nhap(List<SinhVien> DSSV)
        {
            Console.WriteLine("Nhap so luong sinh vien ban dau:");
            int n = int.Parse(Console.ReadLine());
            for(int i=0;i<n; i++)
            {
                SinhVien x = new SinhVien();
                x.Nhap_SV();
                DSSV.Add(x);
            }

        }

        public static void Xuat(List<SinhVien> DSSV)
        {
            Console.WriteLine("\nDanh sach sinh vien hien co:");
            for(int i=0;i<DSSV.Count;i++)
            {
                DSSV[i].Xuat_SV();
            }

        }
        public static void DoSort(List<SinhVien> DSSV)
        {
            int l, m, r, i;
            SinhVien x = new SinhVien();
            for (i = 1; i < DSSV.Count; i++)
            {
                x = DSSV[i];
                l = 0;
                r = i - 1;
                while (l <= r)
                {
                    m = (l + r) / 2;
                    if (x.dtb < DSSV[m].dtb || (x.dtb == DSSV[m].dtb && (x.mssv.CompareTo(DSSV[m].mssv)) < 0))
                    {
                        r = m - 1;
                    }
                    else if (x.dtb > DSSV[m].dtb || (x.dtb == DSSV[m].dtb && (x.mssv.CompareTo(DSSV[m].mssv)) > 0))
                    {
                        l = m + 1;
                    }
                }
                for (int j = i - 1; j >= l; j--)
                {
                    DSSV[j + 1] = DSSV[j];
                }
                DSSV[l] = x;
            }

        }

        public static void Add_Last1(List<SinhVien> DSSV)
        {
            Console.WriteLine("Nhap thong tin sinh vien muon them vao cuoi danh sach: ");
            SinhVien x = new SinhVien();
            x.Nhap_SV();
            DSSV.Add(x);
        }

        public static void Add_Last2(List<SinhVien> DSSV)
        {
            Add_Last1(DSSV);
            DoSort(DSSV);
            Xuat(DSSV);
            Console.WriteLine();
        }

        public static List<SinhVien> DTB_lon_hon_bang_X(List<SinhVien> DSSV)
        {
            Console.Write("Nhap diem trung binh ma ban muon so sanh:  ");
            float x = float.Parse(Console.ReadLine());
            List<SinhVien> DTBLonHonBangX = new List<SinhVien>();
            for(int i=0;i<DSSV.Count;i++)
            {
                if (DSSV[i].dtb >= x)
                {
                    DTBLonHonBangX.Add(DSSV[i]);
                }
            }
            if(DTBLonHonBangX.Count == 0)
            {
                Console.WriteLine("Khong co sinh vien nao co diem trung binh >= {0}", x);
            }
            return DTBLonHonBangX;

        }

        public static List<SinhVien> Xoa_SV_DTB_Lon_Hon_Bang_X(List<SinhVien> DSSV)
        {
            List<SinhVien> XoaDTBLonHonBangX = new List<SinhVien>();
            Console.Write("Nhap diem trung binh ma ban muon so sanh:  ");
            float x = float.Parse(Console.ReadLine());
            for(int i=0;i<DSSV.Count;i++)
            {
                if(DSSV[i].dtb < x)
                {
                    XoaDTBLonHonBangX.Add(DSSV[i]);
                }
            }


            return XoaDTBLonHonBangX;
        }

        public static void Num_SV_DTB_MAX(List<SinhVien> DSSV)
        {
            float MAX = DSSV[0].dtb;
            for(int i=0;i<DSSV.Count;i++)
            {
                if(DSSV[i].dtb > MAX)
                {
                    MAX = DSSV[i].dtb;
                }
            }
            int dem = 0;
            for(int i=0;i<DSSV.Count;i++)
            {
                if (DSSV[i].dtb == MAX)
                {
                    dem++;
                }
            }
            Console.WriteLine("Trong danh sach co "+ dem+" sinh vien co diem trung binh cao nhat la "+Math.Round(MAX,2));
        }


        public static void Main(string[] args)
        {
            List<SinhVien> DSSV1 = new List<SinhVien>();
            Nhap(DSSV1);
            DoSort(DSSV1);
            Xuat(DSSV1);
            Console.WriteLine("\na) Chen 1 sinh vien vao lop hoc");
            Add_Last2(DSSV1);
            Console.WriteLine("\nb) Lay danh sach sinh vien co DTB >= X");
            List<SinhVien> DSSV2 = DTB_lon_hon_bang_X(DSSV1);
            Xuat(DSSV2);
            Console.WriteLine("\nc) Xoa danh sach sinh vien co DTB >= X");
            List<SinhVien> DSSV3 = Xoa_SV_DTB_Lon_Hon_Bang_X(DSSV2);
            Xuat(DSSV3);
            Console.WriteLine("\nd) Tim k sinh vien co diem trung binh cao nhat");
            Num_SV_DTB_MAX(DSSV3);

        }

    }
}
