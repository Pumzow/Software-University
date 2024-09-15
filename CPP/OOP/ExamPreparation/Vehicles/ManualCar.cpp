#include "ManualCar.h"

ManualCar::ManualCar(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel) : Car(maxSpeed, fuel), _shiftSpeeds(shiftSpeeds) {}

void ManualCar::increaseSpeed(int speedIncrease, int fuelConsumtion)
{
	size_t lastShift = findShiftIdx();
	currentSpeed += speedIncrease;
	int fuelConsumtionMultiplier = 1;
	if (lastShift < findShiftIdx())
	{
		fuelConsumtionMultiplier = 2;
	}
	currentFuel -= fuelConsumtion * fuelConsumtionMultiplier;
	Car::increaseSpeed(speedIncrease, fuelConsumtion);
}

void ManualCar::decreaseSpeed(int speedDecrease)
{
	currentSpeed -= speedDecrease;
	Car::decreaseSpeed(speedDecrease);
}

size_t ManualCar::findShiftIdx() const
{
	size_t shift = 0;
	for (size_t i = 0; i < _shiftSpeeds.size() - 1; i++)
	{
		if (currentSpeed >= _shiftSpeeds.at(i))
		{
			shift++;
		}
	}

	return shift;
}