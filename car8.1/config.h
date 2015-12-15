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
	float deltaTime;
};
