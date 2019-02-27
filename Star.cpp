#include "Star.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Starlist::Starlist(){
	this->list = new List();
}

Starlist::~Starlist(){
	//for(int i = 0; i < this->list->size(); i++){
	//	delete list->read(i);
	//}
	delete this->list;
}

long Starlist::addPlanet(){
	Planet * one = new Planet(rand()%3000 + 1);
	list->insert(this->list->size(), one);
	return one->getID();
}

bool Starlist::removePlanet(long id){
	for (unsigned int i = 0; i < this->list->size(); i ++) {
		Planet * curr = this->list->read(i);
		if (id == curr->getID()) {
			this->list->remove(i);
			return true;
		}
	}

	return false;
}

Planet * Starlist::getPlanet(long id){
	for (unsigned int i = 0; i < this->list->size(); i ++) {
		Planet * curr = this->list->read(i);
		if (id == curr->getID()) return curr;
	}

	return NULL;
}

void Starlist::orbit(){
	for(unsigned int i = 0; i < this->list->size(); i++){
		list->read(i)->orbit();
	}
}

void Starlist::printStarInfo(){
	std::cout << "\tThe star currently has " << this->list->size() << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(unsigned int i = 0; i < this->list->size(); i++){
		std::cout << "\t\tPlanet " << (*list->read(i)).getType() << (*list->read(i)).getID() << " is " << (*list->read(i)).getDistance() << " miles away at position " << (*list->read(i)).getPos() << " around the star." << std::endl;
	}
}

unsigned Starlist::getCurrentNumPlanets(){
	return this->list->size();
}


Starvector::Starvector(){
	this->vector = new Vector();
}

Starvector::~Starvector(){
	//for(int i = 0; i < this->vector->size(); i++){
	//	delete vector->read(i);
	//}
	delete this->vector;
}

long Starvector::addPlanet(){
	Planet * one = new Planet(rand()%3001);
	vector->insert(this->vector->size(), one);
	return one->getID();
}

bool Starvector::removePlanet(long id){
	for (unsigned int i = 0; i < this->vector->size(); i ++) {
		Planet * curr = this->vector->read(i);
		if (id == curr->getID()) {
			this->vector->remove(i);
			return true;
		}
	}

	return false;
}

Planet * Starvector::getPlanet(long id){
	for (unsigned int i = 0; i < this->vector->size(); i ++) {
		Planet * curr = this->vector->read(i);
		if (id == curr->getID()) return curr;
	}

	return NULL;
}

void Starvector::orbit(){
	for(unsigned int i = 0; i < this->vector->size(); i++){
		vector->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "\tThe star currently has " << this->vector->size() << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(unsigned int i = 0; i < this->vector->size(); i++){
		std::cout << "\t\tPlanet " << (*vector->read(i)).getType() << (*vector->read(i)).getID() << " is " << (*vector->read(i)).getDistance() << " miles away at position " << (*vector->read(i)).getPos() << " around the star." << std::endl;
	}
}

unsigned int Starvector::getCurrentNumPlanets(){
	return vector->size();
}
