#include "Vehicle.h"
std::ostream& operator << (std::ostream& ostream, const vtat& vtat) {
		ostream << "Durability =" << vtat.v_durability << std::endl;
		ostream << "Fuel =" << vtat.v_fuel << std::endl;
		ostream << "Speed =" << vtat.v_speed << std::endl;
		return ostream;
}

objPosition Vehicle::getPos() { return this->v_Position; };
void Vehicle::setPos(objPosition Position) { this->v_Position = Position; };

int Vehicle::getDurability() { return this->v_stat.v_durability; };
void Vehicle::setDurability(int durability) { this->v_stat.v_durability = durability; };

int Vehicle::getFuel() { return this->v_stat.v_fuel; };
void Vehicle::setFuel(int fuel) { this->v_stat.v_fuel = fuel; };

int Vehicle::getSpeed() { return this->v_stat.v_speed; };
void Vehicle::setSpeed(int speed) { this->v_stat.v_speed = speed; };

std::ostream& operator << (std::ostream& ostream, const Vehicle& vehicle) {
	ostream << "PosX=" << vehicle.v_Position.obj_x << " PosY=" << vehicle.v_Position.obj_y;
	ostream << vehicle.v_stat;
	return ostream;
};

std::ostream& operator << (std::ostream& ostream, const Vehicle* vehicle) {
	ostream << "PosX=" << vehicle->v_Position.obj_x << " PosY=" << vehicle->v_Position.obj_y;
	ostream << vehicle->v_stat;
	return ostream;
};


Vehicle::Vehicle() {
	v_Position.obj_x = 0.0f;
	v_Position.obj_y = 0.0f;
};
Vehicle::~Vehicle() { std::cout << "Vehicle decreased" << std::endl; };