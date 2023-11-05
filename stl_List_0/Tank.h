#pragma once
#include "Vehicle.h"

class Tank:public Vehicle
{
private:
	//float range = 5;
	//float distance = 5000;
	//float turretRotate = 0;
	//float hullRotate = 0;
	int sightRange = 300;
	bool scope = false;
	/*vtat tankStat;*/
public:
	//void setShell();
	//void reload();
	//void fire();
	//void turretRotate();
	//void hullRotate();
	void setSightRange(int range);
	void setDurability(int durability);
	void setFuel(int fuel);
	void setSpeed(int speed);
	/*Tank();*/
	virtual ~Tank();
};

