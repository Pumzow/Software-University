#include "RaceTrack.h"
#include "AutomaticCar.h"
#include "ManualCar.h"
#include <iostream>

bool RaceTrack::isRaceRunning() const
{
    for (size_t i = 0; i < _cars.size(); i++)
    {
        Car& car = *_cars.at(i);
        if (car.currentFuel <= 0) return false;
    }
    return true;
}

void RaceTrack::printWinner()
{
    Car& firstCar = *_cars.at(0);
    Car& secondCar = *_cars.at(1);
    std::string result = "No winner";
    if (firstCar.distanceTravelled == secondCar.distanceTravelled)
    {
        if (firstCar.currentFuel == 0)
        {
            result = "Car with index: 1 won!";
        }
        else if (secondCar.currentFuel == 0)
        {
            result = "Car with index: 0 won!";
        }
    }
    else if (firstCar.distanceTravelled > secondCar.distanceTravelled)
    {
        result = "Car with index: 0 won!";
    }
    else
    {
        result = "Car with index: 1 won!";
    }

    std::cout << result << std::endl;
}

void RaceTrack::printInfo() const
{
    for (size_t i = 0; i < _cars.size(); i++)
    {
        Car& car = *_cars.at(i);
        std::cout << "Car with index: " << i << " has totalDistance: " << car.distanceTravelled << ", is running with " << car.currentSpeed << " speed, has " <<  car.currentFuel << " fuel left" << std::endl;
    }
}

void RaceTrack::createManualCar(const std::vector<int>& shifts, int maxSpeed, int startFuel)
{
    std::unique_ptr<Car> manualCar = std::make_unique<ManualCar>(shifts, maxSpeed, startFuel);
    _cars.push_back(std::move(manualCar));
}

void RaceTrack::createAutomaticCar(int maxSpeed, int startFuel)
{
    std::unique_ptr<Car> automaticCar = std::make_unique<AutomaticCar>(maxSpeed, startFuel);
    _cars.push_back(std::move(automaticCar));
}

void RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion)
{
    for (size_t i = 0; i < _cars.size(); i++)
    {
        Car& car = *_cars.at(i);
        car.increaseSpeed(speedIncrease, fuelConsumtion);
    }
}

void RaceTrack::decreaseSpeed(int speedDecrease)
{
    for (size_t i = 0; i < _cars.size(); i++)
    {
        Car& car = *_cars.at(i);
        car.decreaseSpeed(speedDecrease);
    }
}

void RaceTrack::advance()
{
    for (size_t i = 0; i < _cars.size(); i++)
    {
        Car& car = *_cars.at(i);
        car.advance();
    }
}