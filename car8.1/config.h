#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

struct Config {
	Config() {};
	sf::RenderWindow window;
	sf::ContextSettings settings;
	float speed;
	float speed0;
	float acceleration;
	float isSlowdown;
	float isMoveBack;
	float deltaX;
	float deltaFi;
	sf::ConvexShape carBody;
	sf::CircleShape weel1;
	sf::CircleShape weel2;
	sf::RectangleShape line;
	float deltaTime;
};
