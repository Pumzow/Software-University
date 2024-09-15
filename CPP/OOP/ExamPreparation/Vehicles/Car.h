#ifndef CAR_H
#define CAR_H

class Car {
protected:
	int carMaxSpeed;

public:
	int currentSpeed;
	int currentFuel;
	int distanceTravelled;

	Car(int maxSpeed, int fuel)
	{
		currentSpeed = 0;
		distanceTravelled = 0;
		carMaxSpeed = maxSpeed;
		currentFuel = fuel;
	}

	virtual void increaseSpeed(int speedIncrease, int fuelConsumtion)
	{
		if (currentSpeed > carMaxSpeed) currentSpeed = carMaxSpeed;
		if (currentFuel < 0)
		{
			currentFuel = 0;
			currentSpeed = 0;
		}
	}
	virtual void decreaseSpeed(int speedDecrease)
	{
		if (currentSpeed < 0) currentSpeed = 0;
	}

	void advance()
	{
		distanceTravelled += currentSpeed;
	}
};

#endif /* CAR_H */
