#include "AutomaticCar.h"

AutomaticCar::AutomaticCar(int maxSpeed, int fuel) : Car(maxSpeed, fuel) {}

void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) 
{
	currentSpeed += speedIncrease;
	currentFuel -= fuelConsumtion;
	Car::increaseSpeed(speedIncrease, fuelConsumtion);
}

void AutomaticCar::decreaseSpeed(int speedDecrease)
{
	currentSpeed -= speedDecrease * 2;
	Car::decreaseSpeed(speedDecrease);
}