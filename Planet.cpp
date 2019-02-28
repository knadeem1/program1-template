#include <iostream>
#include "Planet.h"

Planet::Planet(int distance){
	this->distance = distance;
	this->id = (long) this;
	this->pos = rand() % 360;
	char myarray[] = {'h', 'r', 'g'};
	int num = rand() % 3;
	this->type = myarray[num];
}

int Planet::orbit() {
	this->pos ++;
	if (this->pos == 360) {
		this->pos = 0;
	}
	return this->pos;
}
