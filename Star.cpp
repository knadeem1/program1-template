#include "Star.h"
#include <iostream>
/*
Starlist::Starlist(){
	this->list = NULL;
	this->size = 0;
}

Starlist::~Starlist(){
	for(int i =0; i < size; i++){
		delete list[i];
	}
	delete this->list;
}

long Starlist::addPlanet(){	
	Planet * one = new Planet(rand()%3001);
	insert(size+1, one); 
	this->size++;
	return (*one).getID();	
}

bool Starlist::removePlanet(int index){
	return list.remove(index);	
}

Planet * Starlist::getPlanet(int index){
	return list.read(index);	
}

void Starlist::orbit(){
	for(int i = 0; i < size; i++){
		(*list[i]).orbit();
	}	
}

void Starlist::printStarInfo(){
	std::cout << "\tThe star currently has " << size << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << "\t\tPlanet " << (*list[i]).getType() << (*list[i]).getID() << " is " << (*list[i]).getDistance() << " miles away at position " << (*list[i]).getPos() << " around the star." << std::endl;
	}	
}

unsigned int Starlist::getCurrentNumPlanets(){
	return list.size();
}
*/

Starvector::Starvector(){
	this->vector = NULL;
	this->current_planets = 0;
}

Starvector::~Starvector(){
	for(int i =0; i < current_planets; i++){
		delete vector[i];
	}
	delete[] this->vector;
}

long Starvector::addPlanet(){
	Planet * one = new Planet(rand()%3001);
	vector.insert(current_planets+1, one);
	this->current_planets++;
	return (*one).getID();
}

bool Starvector::removePlanet(int index){
	return vector.remove(index);
}

Planet * Starvector::getPlanet(int index){
	return vector.read(index);	
}

void Starvector::orbit(){
	for(int i = 0; i < current_planets; i++){
		(*vector[i]).orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "\tThe star currently has " << current_planets << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(int i = 0; i < current_planets; i++){
		std::cout << "\t\tPlanet " << (*vector[i]).getType() << (*vector[i]).getID() << " is " << (*vector[i]).getDistance() << " miles away at position " << (*vector[i]).getPos() << " around the star." << std::endl;
	}
}

unsigned int Starvector::getCurrentNumPlanets(){
	return vector.size();
}



