using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoDSLK
{
    public class Node
    {
        public SinhVien data;
        public Node pNext;
        public Node()
        {
            this.data = null;
            this.pNext = null;
        }
        public Node(SinhVien data)
        {
            this.data = data;
            this.pNext = null;
        }
    }
}
