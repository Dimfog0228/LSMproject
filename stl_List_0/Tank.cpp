#include "Tank.h"
//Tank::Tank() {
//	tankStat.v_fuel = 200;
//	tankStat.v_durability = 3000;
//	tankStat.v_speed = 70;
//};

void Tank::setDurability(int durability) {	
	Vehicle::setDurability(durability);
};

void Tank::setFuel(int fuel) {
	Vehicle::setFuel(fuel);
};

void Tank::setSpeed(int speed) {
	Vehicle::setSpeed(speed);
};

void Tank::setSightRange(int range) {

};

Tank::~Tank() { std::cout << "Tank Destroyed" << std::endl; }

//Tank::Tank() {};
//Tank::~Tank() {};