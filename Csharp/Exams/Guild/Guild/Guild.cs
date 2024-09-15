using System;
using System.Collections.Generic;
using System.Text;

namespace Guild
{
    public class Guild
    {
        private List<Player> roster;

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

        public Guild(string name, int capacity)
        {
            this.name = name;
            this.capacity = capacity;
            roster = new List<Player>();
        }

        public int Count { get => roster.Count;}

        public void AddPlayer(Player player)
        {
            if (roster.Count < capacity)
            {
                roster.Add(player);
            }
        }

        public bool RemovePlayer(string name)
        {
            foreach (Player player in roster)
            {
                if (player.Name == name)
                {
                    roster.Remove(player);
                    return true;
                }
            }
            return false;
        }

        public void PromotePlayer(string name)
        {
            foreach (Player player in roster)
            {
                if (player.Name == name)
                {
                    player.Rank = "Member";
                    break;
                }
            }
        }
        public void DemotePlayer(string name)
        {
            foreach (Player player in roster)
            {
                if (player.Name == name)
                {
                    player.Rank = "Trial";
                    break;
                }
            }
        }

        public Player[] KickPlayersByClass(string Class)
        {
            List<Player> tempListPlayers = new List<Player>();

            foreach (Player player in roster)
            {
                if (player.Class == Class)
                {
                    tempListPlayers.Add(player);
                }
            }

            foreach (Player player in tempListPlayers)
            {
                roster.Remove(player);
            }

            Player[] TempPlayerArray = tempListPlayers.ToArray();

            return TempPlayerArray;
        }

        public string Report()
        {
            return $"Players in the guild: {this.name}{Environment.NewLine}{String.Join(Environment.NewLine, roster)}";
        }
    }
}
