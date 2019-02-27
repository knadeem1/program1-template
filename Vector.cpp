#include "Vector.h"
#include <iostream>

Vector::Vector() {
	this->planets = new Planet * [0];
	this->array_size = 0;
}

Vector::~Vector() {
	for (int i = 0; i < this->array_size; i ++) {
		delete this->planets[i];
	}
	delete[] this->planets;
}

void Vector::insert(int index, Planet * p) {
	Planet ** new_planets;

	if(index > this->array_size) {
		new_planets = new Planet * [index + 1];
		for (int i = 0; i < this->array_size; i ++) {
			new_planets[i] = planets[i];
		}

		new_planets[index] = p;
		this->array_size = index;
	} else {
		new_planets = new Planet * [this->array_size + 1];
		int i = 0;
		for (; i < index; i ++) {
			new_planets[i] = planets[i];
		}

		new_planets[i] = p;

		for (; i < this->array_size; i++) {
			new_planets[i + 1] = planets[i];
		}
	}

	delete[] planets;
	this->array_size ++;
	this->planets = new_planets;
	//new_planets = NULL
}

Planet * Vector::read(int index) {
	if (this->planets == NULL) {
		return NULL;
	}

	if (index > this->array_size) {
		return NULL;
	}

	return planets[index];
}

bool Vector::remove(int index) {
	if (this->planets == NULL) {
		return false;
	}

	if(index > this->array_size) {
		return false;
	}

	Planet ** temp = new Planet * [this->array_size - 1];
	int i;
	for(i = 0; i < index; i ++){
		temp[i] = planets[i];
	}

	for(i = index; i < this->array_size - 1; i ++){
		temp[i] = planets[i + 1];
	}

	delete[] planets;
	this->array_size --;
	this->planets = temp;
	return true;
}

unsigned Vector::size() {
	return (unsigned) this->array_size;
}
