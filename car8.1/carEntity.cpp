#include "stdafx.h"
#include "config.h"
#include "carEntity.h"

void carInitData(CarData & dataCar) {
	dataCar.speed0 = 0;
	dataCar.speed = 0;
	dataCar.acceleration = -0.00000000001;
	dataCar.isSlowdown = 1;
	dataCar.isMoveBack = -1;
}

void carMove(Config & conf, CarData & dataCar) {
	if (dataCar.speed <= 0) {
		dataCar.isMoveBack = dataCar.isMoveBack * -1.0f;
		dataCar.acceleration = dataCar.acceleration * -1.0f;
	}
	if (dataCar.carBody.getPosition().x < 380 && dataCar.carBody.getPosition().x > 370 && dataCar.acceleration > 0)
		dataCar.acceleration = dataCar.acceleration * -1.0f;
	dataCar.speed = (float)(dataCar.speed0 + dataCar.acceleration * dataCar.isSlowdown *  conf.deltaTime);
	dataCar.speed0 = dataCar.speed;
	dataCar.deltaX = dataCar.speed * conf.deltaTime * dataCar.isMoveBack;
	dataCar.deltaFi = (float)(2 * M_PI * dataCar.speed * conf.deltaTime * dataCar.isMoveBack);
	dataCar.wheel1.rotate(dataCar.deltaFi);
	dataCar.wheel2.rotate(dataCar.deltaFi);
	dataCar.carBody.move(dataCar.deltaX, 0);
	dataCar.wheel1.move(dataCar.deltaX, 0);
	dataCar.wheel2.move(dataCar.deltaX, 0);
}

void carDraw(Config & conf, CarData & dataCar) {
	conf.window.draw(dataCar.wheel1);
	conf.window.draw(dataCar.wheel2);
	conf.window.draw(dataCar.carBody);
	conf.window.draw(dataCar.line);
}