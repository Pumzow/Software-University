namespace SMS.Data
{
    using Microsoft.EntityFrameworkCore;
    using SMS.Data.Models;

    public class SMSDbContext : DbContext
    {
        public DbSet<User> Users { get; set; }
        public DbSet<Product> Products { get; set; }
        public DbSet<Cart> Carts { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer(DatabaseConfiguration.ConnectionString);
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>().HasOne(u => u.Cart)
                     .WithOne(c => c.User)
                      .HasForeignKey<Cart>(c => c.Id);

            modelBuilder.Entity<Cart>().HasOne(c => c.User)
                     .WithOne(u => u.Cart)
                     .HasForeignKey<User>(u => u.Id);
        }
    }
}