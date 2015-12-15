#include "stdafx.h"
#include "config.h"
#include "carEntity.h"

void dataInit(Config & conf) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	conf.window.create(sf::VideoMode(800, 600), "Car", sf::Style::Default, settings);
}


sf::ConvexShape createCar() {
	sf::ConvexShape carBody;
	carBody.setPointCount(8);
	carBody.setPoint(0, sf::Vector2f(0, 0));
	carBody.setPoint(1, sf::Vector2f(100, 0));
	carBody.setPoint(2, sf::Vector2f(100, 50));
	carBody.setPoint(3, sf::Vector2f(150, 50));
	carBody.setPoint(4, sf::Vector2f(150, 100));
	carBody.setPoint(5, sf::Vector2f(-50, 100));
	carBody.setPoint(6, sf::Vector2f(-50, 50));
	carBody.setPoint(7, sf::Vector2f(0, 50));
	carBody.setPosition(100, 300);
	carBody.setFillColor(sf::Color(0, 255, 0));
	return carBody;
}

sf::CircleShape createWheel() {
	sf::CircleShape wheel(15, 10);
	wheel.setOutlineThickness(5);
	wheel.setOutlineColor(sf::Color(0, 0, 255));
	wheel.setFillColor(sf::Color(255, 0, 0));
	wheel.setOrigin(15, 15);
	return wheel;
}

sf::RectangleShape line() {
	sf::RectangleShape line(sf::Vector2f(800, 5));
	line.setFillColor(sf::Color(0, 0, 0));
	line.setPosition(0, 420);
	return line;
}


void runCar(Config & conf, CarDate & dateCar) {
	sf::Clock clock;
	carDataInit(dateCar);
	dateCar.carBody = createCar();
	dateCar.wheel1 = createWheel();
	dateCar.wheel2 = createWheel();
	dateCar.line = line();
	dateCar.wheel1.setPosition(80, 400);
	dateCar.wheel2.setPosition(220, 400);
	dateCar.line.setFillColor(sf::Color(0, 0, 0));
	dateCar.line.setPosition(0, 420);

	while (conf.window.isOpen()) {
		conf.deltaTime = (float)clock.getElapsedTime().asMicroseconds();
		clock.restart();
		sf::Event event;
		while (conf.window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				conf.window.close();
		}
		carMoving(conf, dateCar);
		drawing(conf, dateCar);
		sf::sleep(sf::microseconds((sf::Int64)(1000000 / 60.0) - clock.getElapsedTime().asMicroseconds()));
	}
}

int main(){
	Config conf;
	CarDate dateCar;
	dataInit(conf);
	runCar(conf, dateCar);
    return 0;
}

