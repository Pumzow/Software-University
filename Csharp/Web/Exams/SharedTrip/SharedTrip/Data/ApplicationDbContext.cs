

namespace SharedTrip.Data
{
    using SharedTrip.Data.Models;
    using Microsoft.EntityFrameworkCore;
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext()
        {

        }
        public DbSet<User> Users { get; init; }

        public DbSet<Trip> Trips { get; init; }

        public DbSet<UserTrip> UserTrips { get; init; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer(DatabaseConfiguration.ConnectionString);
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<UserTrip>()
                .HasKey(aa => new { aa.UserId, aa.TripId });

            modelBuilder.Entity<UserTrip>()
                .HasOne(aa => aa.User)
                .WithMany(a => a.UserTrips)
                .HasForeignKey(a => a.UserId);

            modelBuilder.Entity<UserTrip>()
                .HasOne(aa => aa.Trip)
                .WithMany(a => a.UserTrips)
                .HasForeignKey(aa => aa.TripId);

            base.OnModelCreating(modelBuilder);
        }
    }
}
