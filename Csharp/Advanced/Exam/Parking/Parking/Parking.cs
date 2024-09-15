using System;
using System.Collections.Generic;
using System.Text;

namespace Parking
{
    public class Parking
    {
        List<car> data;
        private string type;

        public string Type
        {
            get { return type; }
            set { type = value; }
        }
        private int capacity;

        public int Capacity
        {
            get { return capacity; }
            set { capacity = value; }
        }


        public Parking(string type, int capacity)
        {
            this.type = type;
            this.capacity = capacity;
            data = new List<car>();
        }
    }
}
