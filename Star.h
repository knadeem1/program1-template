#ifndef STARH_KN
#define STARH_KN
#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Starlist{
	private: 
		List * list;
		int size;	
	public:
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();	
};

class Starvector{
	private:
		Vector * vector;
		int current_planets;	
	public:
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
