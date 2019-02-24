#include "Vector.h"
#include <iostream>

Vector::Vector() {
	this->planets = NULL;
	this->current_planets = 0;
}

Vector::~Vector() {
	for (int i = 0; i < this->current_planets; i ++) {
		delete this->planets[i];
	}
	delete[] this->planets;
}

void Vector::insert(int index, Planet * p) {
	bool index_check;
	if (index > this->current_planets) {
		index_check = true;
	}
	
	Planet ** new_planets = NULL;
	if(index_check) {
		new_planets = new Planet * [index + 1];
		for (int i = 0; i < current_planets; i ++) {
			new_planets[i] = this->planets[i];
			this->planets[i] = NULL;
		}

		new_planets[index] = p;
		this->current_planets = index;
	} else {
		new_planets = new Planet * [current_planets + 1];
		int i = 0;
		for (; i < index; i ++) {
			new_planets[i] = this->planets[i];
			this->planets[i] = NULL;
		}
		
		new_planets[++i] = p;

		for (; i < current_planets; i ++) {
			new_planets[i] = this->planets[i + 1];
		}

		this->current_planets ++;
	}

	this->current_planets++;
	delete[] planets;
	this->planets = new_planets;
	new_planets = NULL;
}

Planet * Vector::read(int index) {
	if (index > this->current_planets) {
		return NULL;
	}

	return planets[index];
}

bool Vector::remove(int index) {
	if(planets[index]==NULL){
		return false;
	}
	Planet ** temp = new Planet*[this->current_planets-1];
	int j = 0;
	for(int i = 0; i < current_planets; i++){				
		if(index != (*planets[i]).getID()){
			temp[j] = planets[i]; 
			j++;
		}
		if(index == (*planets[i]).getID()){
			delete planets[i];
			planets[i] = NULL;
		}
	}
	this->current_planets--;
	this->current_planets--;
	delete[] planets;
	this->planets = temp;
	return true;
}

unsigned int Vector::size() {
	return (unsigned int) this->current_planets;
}
	
