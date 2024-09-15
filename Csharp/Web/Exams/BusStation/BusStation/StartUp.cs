namespace BusStation
{
    using MyWebServer;
    using System.Threading.Tasks;
    using MyWebServer.Controllers;
    using MyWebServer.Results.Views;
    using Microsoft.EntityFrameworkCore;
    using BusStation.Data;
    using BusStation.Services;

    public class Startup
    {
        public static async Task Main()
           => await HttpServer
               .WithRoutes(routes => routes
                   .MapStaticFiles()
                   .MapControllers())
               .WithServices(services => services
                   .Add<BusStationDbContext>()
                   .Add<IViewEngine, CompilationViewEngine>()
                   .Add<IValidator, Validator>()
                   .Add<IPasswordHasher, PasswordHasher>())
               .WithConfiguration<BusStationDbContext>(context => context
                   .Database.Migrate())
               .Start();
    }
}
