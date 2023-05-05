using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace DemoDSLK
{

    public class Program
    {
        
        public static Node CreateNode(SinhVien x)     //Tao 1 node moi
        {
            x.Nhap_SV();
            Node Node_SV = new Node(x);
            return Node_SV;
        }
        public static bool IsEmptyList(LinkedList DSLK_SV)     //Kiem tra danh sach rong
        {
            if (DSLK_SV.pHead == null)
            {
                return true;
            }
            return false;
        }
        public static int SizeOfList(LinkedList DSLK_SV)     //Lay so node trong danh sach
        {
            int nSize = 0;
            Node Node_SV = DSLK_SV.pHead;
            while (Node_SV!= null)
            {
                nSize++;
                Node_SV = Node_SV.pNext;
            }
            return nSize;
        }
        public static bool IsFullList(LinkedList DSLK_SV)     //Kiem tra danh sach day
        {
            if (SizeOfList(DSLK_SV) == 100)
            {
                return true;
            }
            return false;
        }
        public static void Add_First(LinkedList DSLK_SV, Node d)     //Chen vao dau danh sach
        {
            //Console.WriteLine("Nhap thong tin sinh vien muon chen vao dau danh sach:");
            SinhVien x = new SinhVien();
            d = CreateNode(x);
            if (IsEmptyList(DSLK_SV) == true)
            {
                DSLK_SV.pHead = DSLK_SV.pTail = d;
            }
            else if (IsFullList(DSLK_SV) == true)
            {
                Console.WriteLine("Danh sach da day nen khong the them!");
            }
            else
            {
                d.pNext = DSLK_SV.pHead;
                DSLK_SV.pHead = d;
            }
        }
        public static void Add_Last(LinkedList DSLK_SV, Node d)     //Chen vao cuoi danh sach
        {
            //Console.WriteLine("Nhap thong tin sinh vien muon chen vao cuoi danh sach:");
            SinhVien x = new SinhVien();
            d = CreateNode(x);
            if (IsEmptyList(DSLK_SV) == true)
            {
                DSLK_SV.pHead = DSLK_SV.pTail = d;
            }
            else if (IsFullList(DSLK_SV) == true)
            {
                Console.WriteLine("Danh sach da day nen khong the them!");
            }
            else
            {
                DSLK_SV.pTail.pNext = d;
                DSLK_SV.pTail = d;
            }
        }
        public static void Print_List(LinkedList DSLK_SV)     //Xuat danh sach
        {
            Console.WriteLine("\nDanh sach sinh vien hien co: ");
            Node Node_SV = DSLK_SV.pHead;
            while (Node_SV != null)
            {
                Console.WriteLine("Ho va ten: "+Node_SV.data.HOTEN+"     MSSV: "+Node_SV.data.MSSV+"     DTB: "+Math.Round(Node_SV.data.DTB,2));
                Node_SV = Node_SV.pNext;

            }
        }
        public static void Remove_First(LinkedList DSLK_SV)     //Xoa node dau danh sach
        {
            if(IsEmptyList(DSLK_SV)==true)
            {
                Console.WriteLine("Danh sach dang bi rong!");
            }
            else
            {
                Node Node_SV= DSLK_SV.pHead;
                if(DSLK_SV.pHead==DSLK_SV.pTail)
                {
                    DSLK_SV.pHead = DSLK_SV.pTail = null;
                }
                else
                {
                    DSLK_SV.pHead = DSLK_SV.pHead.pNext;
                }
                Node_SV = null;
            }

        }
        public static void Remove_Last(LinkedList DSLK_SV)     //Xoa node cuoi danh sach
        {
            if (IsEmptyList(DSLK_SV) == true)
            {
                Console.WriteLine("Danh sach dang bi rong!");
            }
            else
            {
                Node Node_SV1 = DSLK_SV.pTail;
                if (DSLK_SV.pHead == DSLK_SV.pTail)
                {
                    DSLK_SV.pHead = DSLK_SV.pTail = null;
                }
                else
                {
                    Node Node_SV2 = new Node();
                    for(Node_SV2=DSLK_SV.pHead;Node_SV2.pNext!=DSLK_SV.pTail;Node_SV2=Node_SV2.pNext)
                    {

                    }
                    Node_SV2.pNext = null;
                    DSLK_SV.pTail = Node_SV2;
                }
                Node_SV1 = null;
            }

        }

        public static void Search_Node(LinkedList DSLk_SV)
        {
            Console.Write("\nNhap MSSV sinh vien muon tim trong danh sach:  ");
            int n = int.Parse(Console.ReadLine());
            int dem = 0;
            bool temp = false;
            Node Node_SV1 = DSLk_SV.pHead;
            Node Node_SV2 = new Node();
            while(Node_SV1!=null)
            {
                if (Node_SV1.data.MSSV==n)
                {
                    Node_SV2 = Node_SV1;
                    temp =true;     //tim thay sinh vien
                    break;
                }
                Node_SV1 = Node_SV1.pNext;
                dem++;     //luu lai vi tri sinh vien
            }
            if(temp==false)
            {
                Console.WriteLine("Khong tim thay sinh vien co MSSV: " + n + " trong danh sach!");
            }
            else
            {
                Console.WriteLine("Da tim thay sinh vien " + Node_SV2.data.HOTEN + " o vi tri thu " + dem + " trong danh sach!");
            }
        }
        /*public static void Add_Last_For_List_Bigger(LinkedList DSLK_SV, Node d)
        {

        }*/

        public static LinkedList Bigger_Than_X(LinkedList DSLK_SV)
        {
            Console.Write("\nNhap DTB ma ban muon so sanh:  ");
            float n = float.Parse(Console.ReadLine());
            LinkedList DSLK_SV_Temp = new LinkedList();
            Node Node_SV = DSLK_SV.pHead;
            while(Node_SV!=null)
            {
                if(Node_SV.data.DTB>=n)
                {
                    if (IsEmptyList(DSLK_SV_Temp) == true)
                    {
                        DSLK_SV_Temp.pHead = DSLK_SV_Temp.pTail = Node_SV;
                    }
                    else
                    {
                        DSLK_SV_Temp.pTail.pNext = Node_SV;
                        DSLK_SV_Temp.pTail = Node_SV;
                    }
                }
                Node_SV=Node_SV.pNext;
            }
            if(IsEmptyList(DSLK_SV_Temp)==true)
            {
                Console.WriteLine("Trong danh sach khong co sinh vien nao co DTB >= " + n);

            }
            else
            {
                Console.WriteLine("Danh sach sinh vien co DTB >= " + n + " la:");
            }
            return DSLK_SV_Temp;
            
        }
        public static void RemoveNode(LinkedList list, Node x)
        {
            Node pDel = list.pHead;
            if (pDel == null)
            {
                Console.WriteLine("DS rong!");
            }
            else
            {
                Node pPre = new Node();
                while (pDel != null)
                {
                    if (pDel == x)
                    {
                        break;  //tim thay pDel
                    }
                    pPre = pDel;
                    pDel = pDel.pNext;
                }
                if (pDel == null)
                {
                    Console.WriteLine("Khong tim thay dia chi can xoa");
                }
                else
                {
                    if (pDel == list.pHead)
                    {
                        list.pHead = list.pHead.pNext;
                        pDel.pNext = null;
                        //delete pDel;
                        pDel = null;
                    }
                    else
                    {
                        pPre.pNext = pDel.pNext;
                        pDel.pNext = null;
                        //delete pDel;
                        pDel = null;
                    }
                }
            }
        }
        public static LinkedList Remove_Bigger_Than_X(LinkedList DSLK_SV)
        {
            Console.Write("\nNhap DTB ma ban muon so sanh:  ");
            float n = float.Parse(Console.ReadLine());
            //LinkedList DSLK_SV_Temp = new LinkedList();
            Node Node_SV = DSLK_SV.pHead;
            while (Node_SV != null)
            {
                if (Node_SV.data.DTB >= n)
                {
                    RemoveNode(DSLK_SV, Node_SV);
                }
                Node_SV = Node_SV.pNext;
            }
            /*if (IsEmptyList(DSLK_SV_Temp) == true)
            {
                Console.WriteLine("Danh sach sinh vien sau khi xoa sinh vien co DTB >= " + n + " la danh sach rong vi tat ca sinh vien deu co DTB >= " + n);

            }
            else
            {*/
                Console.WriteLine("Danh sach sinh vien sau khi xoa sinh vien co DTB >= " + n + " la:");
            //}
            return DSLK_SV;

        }
        public static void Number_DTB_MAX(LinkedList DSLK_SV)
        {
            Node Node_SV1 = DSLK_SV.pHead;
            for(Node Node_SV2=DSLK_SV.pHead;Node_SV2!=null;Node_SV2=Node_SV2.pNext)
            {
                if(Node_SV1.data.DTB<Node_SV2.data.DTB)
                {
                    Node_SV1 = Node_SV2;
                }
            }
            int dem = 0;
            for(Node Node_SV3 = DSLK_SV.pHead;Node_SV3!=null;Node_SV3=Node_SV3.pNext)
            {
                if(Node_SV3.data.DTB==Node_SV1.data.DTB)
                {
                    dem++;
                }
            }
            Console.WriteLine("Co " + dem+" sinh vien co DTB cao nhat trong danh sach!");
        }
        

        public static void Main(string[] args)
        {
            LinkedList DSLK_SV1 = new LinkedList();
            Console.Write("Nhap so luong sinh vien ban dau:  ");
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                Node Node_SV1 = new Node();
                Add_Last(DSLK_SV1, Node_SV1);
            }
            Print_List(DSLK_SV1);
            //Search_Node(DSLK_SV1);
            LinkedList DSLK_SV2 = Bigger_Than_X(DSLK_SV1);
            Print_List(DSLK_SV2);
            LinkedList DSLK_SV3 = Remove_Bigger_Than_X(DSLK_SV2);
            Print_List(DSLK_SV3);
            Number_DTB_MAX(DSLK_SV3);
            Console.ReadKey();
        }

    }
    

}
