#pragma once
#include "config.h"

struct CarDate {
	CarDate() {};
	float speed;
	float speed0;
	double acceleration;
	float isSlowdown;
	float isMoveBack;
	float deltaX;
	float deltaFi;
	sf::ConvexShape carBody;
	sf::CircleShape wheel1;
	sf::CircleShape wheel2;
	sf::RectangleShape line;
};

void carDataInit(CarDate & dateCar);
void carMoving(Config & conf, CarDate & dateCar);
void drawing(Config & conf, CarDate & dateCar);