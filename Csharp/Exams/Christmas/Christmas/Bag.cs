using System;
using System.Collections.Generic;
using System.Text;

namespace Christmas
{
    public class Bag
    {
        private List<Present> data;

        private string color;
        public string Color
        {
            get { return color; }
            private set { color = value; }
        }
        private int capacity;
        public int Capacity
        {
            get { return capacity; }
            private set { capacity = value; }
        }
        public Bag(string color, int capacity)
        {
            this.color = color;
            this.capacity = capacity;
            data = new List<Present>();
        }
        public void Add(Present present)
        {
            if (data.Count < capacity)
            {
                data.Add(present);
            }
        }
        public bool Remove(string name)
        {
            foreach (Present present in data)
            {
                if (present.Name == name)
                {
                    data.Remove(present);
                    return true;
                }
            }
            return false;
        }
        public Present GetHeaviestPresent()
        {
            Present tempPresent = data[0];

            foreach (Present present in data)
            {
                if (present.Weight > tempPresent.Weight)
                {
                    tempPresent = present;
                }
            }
            return tempPresent;
        }
        public Present GetPresent(string name)
        {
            foreach (Present present in data)
            {
                if (present.Name == name)
                {
                    return present;
                }
            }
            throw new Exception();
        }
        public int Count => data.Count;

        public string Report()
        {
            return $"{color} bag contains:{Environment.NewLine}{string.Join(Environment.NewLine, data)}";
        }
    }
}
