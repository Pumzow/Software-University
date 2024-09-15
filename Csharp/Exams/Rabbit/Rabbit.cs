using System;
using System.Collections.Generic;
using System.Text;

namespace Rabbits
{
    public class Rabbit
    {
        private string name;
        public string Name
        {
            get { return name; }
            private set { name = value; }
        }
        private string species;
        public string Species
        {
            get { return species; }
            private set { species = value; }
        }
        private bool available = true;
        public bool Available
        {
            get { return available; }
            set { available = value; }
        }

        public Rabbit(string name, string species)
        {
            this.name = name;
            this.species = species;
            this.available = true;
        }

        public override string ToString()
        {
            return $"Rabbit ({species}): {name}";
        }
    }
}
