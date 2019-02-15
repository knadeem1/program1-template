#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "Star.h"
#include "Planet.h"

Star::Star() {
	this->current_planets = 0;
	this->planets = NULL;
}

Star::~Star() {
	for (int i = 0; i < this->current_planets; i ++) {
		delete this->planets[i];
	}

	delete[] this->planets;
}

int Star::addPlanet() {
	Planet ** new_planets = new Planet * [this->current_planets + 1];
	for (int i = 0; i < this->current_planets; i ++) {
		new_planets[i] = this->planets[i];
		this->planets[i] = NULL;
	}

	new_planets[this->current_planets] = new Planet(rand() % 3000 + 1, this->next_id ++);
	this->current_planets ++;
	this->planets = new_planets;
	return next_id - 1;
}

bool Star::removePlanet(int id) {
	if (current_planets == 0) {
		return false;
	}

	bool found = false;
	for (int i = 0; i < this->current_planets; i ++) {
		if (this->planets[i]->getID() == id) {
			found = true;
			break;
		}
	}
	
	if(found) {
		Planet ** new_planets = new Planet * [this->current_planets - 1];
		int offset = 0;
		for (int i = 0; i < this->current_planets - 1; i ++) {
			if (this->planets[i]->getID() == id) {
				offset = 1;
				this->planets[i] = NULL;
			}
			new_planets[i] = this->planets[i + offset];
			this->planets[i] = NULL;
		}

		this->current_planets --;
		this->planets = new_planets;
		return found;
	}

	return found;
}

/*

bool Star::removePlanet(int id) {
	if (current_planets == 0) {
		return false;
	}

	bool found = false;
	for (int i = 0; i < this->current_planets; i ++) {
		if (this->planets[i]->getID() == id) {
			found = true;
			break;
		}
	}
	
	if(found) {
		Planet ** new_planets = new Planet * [this->current_planets - 1];
		int offset = 0;
		for (int i = 0; i < this->current_planets - 1; i ++) {
			if (this->planets[i]->getID() == id) {
				offset = 1;
				this->planets[i] = NULL;
			}
			new_planets[i] = this->planets[i + offset];
			this->planets[i] = NULL;
		}

		this->current_planets --;
		this->planets = new_planets;
		return found;
	}

	return found;
}
*/

Planet * Star::getPlanet(int id) {
	for (int i = 0; i < this->current_planets; i ++) {
		if (this->planets[i]->getID() == id) {
			return this->planets[i];
		}
	}
	
	return NULL;
}

Planet Star::getFurthest() {
	Planet * furthest = this->planets[0];
	for (int i = 0; i < this->current_planets; i ++) {
		if (this->planets[i]->getDistance() > furthest->getDistance()) {
			furthest = this->planets[i];
		}
	}
	return *furthest;
}

void Star::orbit() {
	for (int i = 0; i < this->current_planets; i ++) {
		this->planets[i]->orbit();
	}
}

void Star::printStarInfo() {
	std::cout << "Planets:" << std::endl;
	for (int i = 0; i < this->current_planets; i ++) {
		printf("\tPlanet %c%d is %d million miles away at position %d around the star.\n", this->planets[i]->getType(), i, this->planets[i]->getDistance(), this->planets[i]->getPos());
	}
}


