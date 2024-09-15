using System;
using System.Collections.Generic;
using System.Text;

namespace Parking
{
    public class Car
    {
        private string manufacturer;

        public string Manufacturer
        {
            get { return manufacturer; }
            set { manufacturer = value; }
        }
        private string model;

        public string Model
        {
            get { return model; }
            set { model = value; }
        }
        private int year;

        public int Year
        {
            get { return year; }
            set { year = value; }
        }

        public Car(string manufaturer, string model, int year)
        {
            this.manufacturer = manufacturer;
            this.model = model;
            this.year = year;
        }
        public override ToString()
        {
            return $"{manufacturer} {model} ({year})";
        }
    }
}
