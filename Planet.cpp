#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "Planet.h"

Planet::Planet(int distance){
	this->distance = distance;
	this->id = this;
	this->pos = rand() % 360 + 1;
	int planet_type = rand() % 3;
	switch(planet_type) {
		case 0:
			this->type = 'h';
			break;
		case 1:
			this->type = 'r';
			break;
		case 2:
			this->type = 'g';
			break;
	}
}

int Planet::orbit() {
	this->pos ++;
	if (this->pos >= 360) {
		this->pos -= 360;
	}
	return this->pos;
}

