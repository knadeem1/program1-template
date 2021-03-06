#ifndef HEADER_VECTOR
#define HEADER_VECTOR
#include "Planet.h"

class Vector {
	private:
		Planet ** planets;
		int array_size;
	public:
		Vector();
		~Vector();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};



#endif
