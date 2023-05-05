using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoDSLK
{
    public class SinhVien
    {
        private string hoten;
        private int mssv;
        private float dtb;
        public SinhVien()
        {
            this.hoten = "";
            this.mssv = 0;
            this.dtb = 0;
        }
        public SinhVien(string hoten, int mssv, float dtb)
        {
            this.hoten = hoten;
            this.mssv = mssv;
            this.dtb = dtb;
        }
        public string HOTEN
        {
            get
            {
                return this.hoten;
            }
            set
            {
                this.hoten = value;
            }
        }
        public int MSSV
        {
            get
            {
                return this.mssv;
            }
            set
            {
                this.mssv = value;
            }
        }
        public float DTB
        {
            get
            {
                return this.dtb;
            }
            set
            {
                if (value > 0 && value <= 10)
                {
                    this.dtb = value;
                }
            }
        }
        public void Nhap_SV()
        {
            Console.Write("Nhap ho va ten: ");
            this.hoten = Console.ReadLine();
            Console.Write("Nhap MSSV: ");
            this.mssv = int.Parse(Console.ReadLine());
            Console.Write("Nhap Diem trung binh: ");
            this.dtb = float.Parse(Console.ReadLine());
        }
        public void Xuat_SV()
        {
            Console.WriteLine("Ho ten: " + this.hoten + "     MSSV: " + this.mssv + "     Diem trung binh:" + Math.Round(this.dtb, 2));
        }

    }
}
