#ifndef HEADER_PLANET
#define HEADER_PLANET

class Planet{
	private:
		long int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(int);
		int orbit();
		long int getID();
        	int getDistance();
        	int getPos();
		char getType();
		//you may add any additional methods you may need.
};
inline long int Planet::getID(){
	return this->id;
}
inline int Planet::getDistance() {
	return this->distance;
}

inline int Planet::getPos() {
	return this->pos;
}

inline char Planet::getType() {
	return this->type;
}

#endif
