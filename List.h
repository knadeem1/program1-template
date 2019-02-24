#ifndef HEADER_LIST
#define HEADER_LIST

#include "Planet.h"

class Node {
	public:
		Planet * data;
		Node * next;
		Node * prev;
};

class List {
	private:
		unsigned int current_planets;
	public:
		Node * head;
		Node * tail;
		List();
		~List();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};

#endif
