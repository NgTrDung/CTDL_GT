using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DSSV
{
    internal class SinhVien
    {
        private string HOTEN, MSSV;
        private float DTB;
        public SinhVien()
        {

        }
        public SinhVien(string hoten, string mssv, float dtb)
        {
            this.HOTEN = hoten;
            this.MSSV = mssv;
            this.DTB = dtb;
        }
        public string hoten
        {
            get { return this.HOTEN; }
            set { this.HOTEN = value; }
        }
        public string mssv
        {
            get { return this.MSSV; }
            set { this.MSSV = value; }
        }
        public float dtb
        {
            get { return this.DTB; }
            set
            {
                if (value < 0 || value > 10)
                {
                    throw new ArgumentOutOfRangeException($"{nameof(value)} must be between 0 and 10.");
                }
                this.DTB = value;
            }
        }
        public void Nhap_SV()
        {
            Console.Write("Nhap Ho va Ten: ");
            this.hoten = Console.ReadLine();
            Console.Write("Nhap MSSV: ");
            this.mssv = Console.ReadLine();
            Console.Write("Nhap Diem trung binh: ");
            this.dtb = float.Parse(Console.ReadLine());
        }
        public void Xuat_SV()
        {
            Console.WriteLine("Ho ten: " + this.HOTEN + "\tMSSV: " + this.MSSV + "\tDiem trung binh:" + Math.Round(this.DTB, 2));
        }
    }
}
