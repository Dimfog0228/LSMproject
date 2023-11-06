#pragma once
#include "Vehicle.h"

class FoodTruct :public Vehicle
{
private:


public:
	
	void setDurability(int durability);
	void setFuel(int fuel);
	void setSpeed(int speed);
	//FoodTruct();
	virtual ~FoodTruct();
};
