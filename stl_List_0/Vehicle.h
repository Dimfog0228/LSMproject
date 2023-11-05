#pragma once
#include <iostream>

class objPosition {
public:
	float obj_x = 0.0f;
	float obj_y = 0.0f;
};

struct vtat {
	int v_durability = 100;
	int v_fuel = 100;
	int v_speed = 60;
	friend std::ostream& operator << (std::ostream& ostream, const vtat& vtat);
	/*{

		ostream << "Durability =" << vtat.v_durability << std::endl;
		ostream << "Fuel =" << vtat.v_fuel << std::endl;
		ostream << "Speed =" << vtat.v_speed << std::endl;

		return ostream;
	}*/

};



class Vehicle
{
private:
	objPosition v_Position;
	vtat v_stat;
public:
	objPosition getPos();
	virtual void setPos(objPosition Position);

	int getDurability();
	virtual void setDurability(int durability);

	int getFuel();
	virtual void setFuel(int fuel);

	int getSpeed();
	virtual void setSpeed(int speed);

	friend std::ostream& operator << (std::ostream& ostream,
		const Vehicle& vehicle);

	friend std::ostream& operator << (std::ostream& ostream,
		const Vehicle* vehicle);
public:
	Vehicle();
	virtual ~Vehicle();
};

