#ifndef HEADER_VECTOR
#define HEADER_VECTOR

class Vector {
	private:
		Planet ** planets;
		int current_planets;
		unsigned int size;
	public:
		Vector();
		~Vector();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
}



#endif
