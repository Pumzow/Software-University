using System;
using System.Collections.Generic;
using System.Text;

namespace Guild
{
    public class Player
    {
        private string name;

        public string Name
        {
            get { return name; }
            private set { name = value; }
        }

        private string myClass;

        public string Class
        {
            get { return myClass; }
            private set { myClass = value; }
        }

        private string rank = "Trial";

        public string Rank
        {
            get { return rank; }
            set { rank = value; }
        }

        private string description = "n/a";

        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        public Player(string name, string Class)
        {
            this.name = name;
            this.myClass = Class;
        }

        public override string ToString()
        {
            return $"Player {name}: {myClass}{Environment.NewLine}Rank: {rank}{Environment.NewLine}Description: {description}";
        }
    }
}
