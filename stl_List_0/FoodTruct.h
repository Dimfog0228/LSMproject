#pragma once
#include "Vehicle.h"

class FoodTruct :public Vehicle
{
private:
	//float range = 5;
	//float distance = 5000;
	//float turretRotate = 0;
	//float hullRotate = 0;


public:
	//void setShell();
	//void reload();
	//void fire();
	//void turretRotate();
	//void hullRotate();
	
	void setDurability(int durability);
	void setFuel(int fuel);
	void setSpeed(int speed);
	//FoodTruct();
	virtual ~FoodTruct();
};
