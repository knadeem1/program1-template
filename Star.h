#ifndef STARH_KN
#define STARH_KN
#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Starlist{
	private: 
		int size;	
	public:
		List * list;
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned getCurrentNumPlanets();	
};

class Starvector{
	private:
		int current_planets;	
	public:
		Vector * vector;
		Starvector();
		~Starvector();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();	
};

#endif 
