#include <cstdlib>
#include "List.h"

List::List() {
	this->current_planets = 0;
	this->head = NULL;
	this->tail = NULL;
}

List::~List() {
	if (this->head != NULL) {
		Node * temp = head;
		Node * nextN = temp->next;
		while (nextN != NULL) {
			temp->next = NULL;
			temp->prev = NULL;
			delete temp->data;
			temp = nextN;
			nextN = nextN->next;
		}
	}

	delete this->head;
	delete this->tail;
}

void List::insert(int index, Planet * p) {
	if(head == NULL) {
		head = new Node();
		head->data = p;
		head->next = NULL;
		tail = head;
	}

	Node * temp = head;
	for (int i = 0; i < index; i ++) {
		if (temp->next == NULL) {
			break;
		} else {
			temp = temp->next;
		}
	}

	temp->next = new Node();
	temp->next->data = p;
	temp->next->prev = temp;
	temp->next->next = NULL;

	this->current_planets ++;
	this->tail = temp->next;
}

Planet * List::read(int index) {
	if (this->head == NULL) {
		return NULL;
	}

	Node * temp = this->head;
	for (int i = 0; i < index; i ++) {
		if (temp->next == NULL) {
			return NULL;
		} else {
			temp = temp->next;
		}
	}

	return temp->data;
}

bool List::remove(int index) {
	if (this->head == NULL) { //empty list
		return false;
	}

	Node * temp = this->head;
	int i;
	for (i = 0; i < index; i ++) {
		if (temp->next == NULL) {
			return false;
		} else {
			temp = temp->next;
		}
	}

	if (index == 0 && this->current_planets == 1) { //when removing the first node and size of list is 1
		this->head = NULL;
		this->tail = NULL;
		//list is now empty
	} else if(index == 0) { //when removing first node
		this->head = this->head->next;
		this->head->prev->next = NULL;
		this->head->prev = NULL;
		//head now points to second node and
		//second node previous is now null
	} else {
		Node * prev = temp->prev;
		prev->next = temp->next;
		temp->next->prev = prev;

		temp->next = NULL;
		temp->prev = NULL;
		if(i == index) { //if last node, change tail to new last node
			this->tail = prev;
		}
	}

	this->current_planets --;
	return true;

}

unsigned List::size() {
	return this->current_planets;
}
