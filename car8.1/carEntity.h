#pragma once
#include "config.h"

struct CarData {
	CarData() {};
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

void carInitData(CarData & dataCar);
void carMove(Config & conf, CarData & dataCar);
void carDraw(Config & conf, CarData & dataCar);