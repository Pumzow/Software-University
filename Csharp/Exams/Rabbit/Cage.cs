using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Rabbits
{
    public class Cage
    {
        private List<Rabbit> data;

        private string name;
        public string Name
        {
            get { return name; }
            private set { name = value; }
        }
        private int capacity;
        public int Capacity
        {
            get { return capacity; }
            private set { capacity = value; }
        }
        public Cage(string name, int capacity)
        {
            this.name = name;
            this.capacity = capacity;
            data = new List<Rabbit>();
        }

        public void Add(Rabbit rabbit)
        {
            if (data.Count < capacity)
            {
                data.Add(rabbit);
            }
        }
        public bool RemoveRabbit(string name)
        {
            foreach (var rabbit in data)
            {
                if (rabbit.Name == name)
                {
                    data.Remove(rabbit);
                    return true;
                }
            }
            return false;
        }
        public void RemoveSpecies(string species)
        {
            data.RemoveAll(r => r.Species == species);
            /*foreach (var rabbit in data)
            {
                if (rabbit.Species == species)
                {
                    data.Remove(rabbit);
                }
            }*/
        }
        public Rabbit SellRabbit(string name)
        {
            Rabbit bunny = data.FirstOrDefault(x => x.Name == name);
            bunny.Available = false;
            foreach (var rabbit in data)
            {
                if (rabbit.Name == bunny.Name)
                {
                    rabbit.Available = false;
                }
            }
            return bunny;
        }
        public Rabbit[] SellRabbitsBySpecies(string species)
        {
            List<Rabbit> array = new List<Rabbit>();
            foreach (var rabbit in data)
            {
                if (rabbit.Species == species)
                {
                    rabbit.Available = false;
                    array.Add(rabbit);
                }
            }
            return array.ToArray();
        }
        public int Count => data.Count;
        public string Report()
        {
            List<Rabbit> ne = new List<Rabbit>();
            foreach (var rabbit in data)
            {
                if (rabbit.Available == true)
                {
                    ne.Add(rabbit);
                }
            }
            return $"Rabbits available at {name}:{Environment.NewLine}{string.Join(Environment.NewLine, ne)}";
        }
    }
}
