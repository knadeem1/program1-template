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

void Vector::insert(int index, Planet * p){ 
	if(index > array_size) {
		Planet ** new_planets = new Planet * [index + 1];
		for (int i = 0; i < array_size; i++) {
			new_planets[i] = planets[i];
		}
		for(int i = array_size; i < index + 1; i++){
			if(i==index){
				new_planets[i] = p;
			}
			else{
				new_planets[i] = NULL;
			}
		}
		array_size = index+1;
		delete[] planets;
		planets = new_planets;
	} else if(index == array_size){
		Planet ** new_planets = new Planet * [++array_size];
		for (int i = 0; i < index; i++) {				 
			new_planets[i] = planets[i];
	        }
		new_planets[index] = p;
		delete[] planets;
		planets = new_planets;
	} else if(index < array_size){
		if(planets[index] != NULL){
			Planet ** new_planets = new Planet*[array_size];
			for(int i =0; i < array_size; i++){
				if(i != index){ 
					new_planets[i] = planets[i];
				}
				else{
					new_planets[index] = p;
				}
			}
			delete[] planets;
			planets = new_planets;
		}
		else{
			Planet ** new_planets = new Planet*[++array_size];
			int one = index;
			for(int i = 0; i < array_size; i++){
				if(i < index){
					new_planets[i] = planets[i];
				}else if(i == index){
					new_planets[i] = p;
				}else{
					new_planets[i] = planets[one++];
				}
			}
			delete[] planets;
			planets = new_planets;
		}
	}
}

Planet * Vector::read(int index) {
	if (index >= this->array_size || this->planets == NULL) {
		return NULL;
	}
	return planets[index];
}

bool Vector::remove(int index) {
	if(index >= this->array_size || this->planets==NULL){
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
