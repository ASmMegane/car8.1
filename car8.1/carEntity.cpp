#include "stdafx.h"
#include "config.h"
#include "carEntity.h"

void carDataInit(CarDate & dateCar) {
	dateCar.speed0 = 0;
	dateCar.speed = 0;
	dateCar.acceleration = -0.00000000001;
	dateCar.isSlowdown = 1;
	dateCar.isMoveBack = -1;
}

void carMoving(Config & conf, CarDate & dateCar) {
	if (dateCar.speed <= 0) {
		dateCar.isMoveBack = dateCar.isMoveBack * -1.0f;
		dateCar.acceleration = dateCar.acceleration * -1.0f;
	}
	if (dateCar.carBody.getPosition().x < 380 && dateCar.carBody.getPosition().x > 370 && dateCar.acceleration > 0)
		dateCar.acceleration = dateCar.acceleration * -1.0f;
	dateCar.speed = (float)(dateCar.speed0 + dateCar.acceleration * dateCar.isSlowdown *  conf.deltaTime);
	dateCar.speed0 = dateCar.speed;
	dateCar.deltaX = dateCar.speed * conf.deltaTime * dateCar.isMoveBack;
	dateCar.deltaFi = (float)(2 * M_PI * dateCar.speed * conf.deltaTime * dateCar.isMoveBack);
	dateCar.wheel1.rotate(dateCar.deltaFi);
	dateCar.wheel2.rotate(dateCar.deltaFi);
	dateCar.carBody.move(dateCar.deltaX, 0);
	dateCar.wheel1.move(dateCar.deltaX, 0);
	dateCar.wheel2.move(dateCar.deltaX, 0);
}

void drawing(Config & conf, CarDate & dateCar) {
	conf.window.clear(sf::Color(255, 255, 255));
	conf.window.draw(dateCar.wheel1);
	conf.window.draw(dateCar.wheel2);
	conf.window.draw(dateCar.carBody);
	conf.window.draw(dateCar.line);
	conf.window.display();
}