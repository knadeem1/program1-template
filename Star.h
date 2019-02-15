#ifndef HEADER_STAR
#define HEADER_STAR
#include "Planet.h"

class Star{
	private:
		int current_planets;
		int next_id;
	public:
		Planet ** planets;
		Star();
		~Star();
		int addPlanet();
		bool removePlanet(int);
		Planet getFurthest();
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

inline int Star::getCurrentNumPlanets() {
	return this->current_planets;
}

#endif
