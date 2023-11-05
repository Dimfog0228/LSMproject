#include "FoodTruct.h"

void FoodTruct::setDurability(int durability) {
	Vehicle::setDurability(durability);
};

void FoodTruct::setFuel(int fuel) {
	Vehicle::setFuel(fuel);
};

void FoodTruct::setSpeed(int speed) {
	Vehicle::setSpeed(speed);
};


FoodTruct::~FoodTruct() { std::cout << "FoodTruct Left" << std::endl; }

