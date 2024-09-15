using System;
using System.Collections.Generic;
using System.Text;

namespace Christmas
{
    public class Present
    {
        private string name;

        public string Name
        {
            get { return name; }
            private set { name = value; }
        }
        private double weight;
        public double Weight
        {
            get { return weight; }
            private set { weight = value; }
        }
        private string gender;
        public string Gender
        {
            get { return gender; }
            private set { gender = value; }
        }

        public Present(string name,double weight, string gender)
        {
            this.name = name;
            this.weight = weight;
            this.Gender = gender;
        }

        public override string ToString()
        {
            return $"Present {name} ({weight}) for a {gender}";
        }
    }
}
