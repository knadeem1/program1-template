#include <cstdlib>
#include <iostream>
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
			//delete temp->data;
			temp = nextN;
			nextN = nextN->next;
		}
	}

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

//BREAKS WHEN USED ON LAST NODE
bool List::remove(int index) {
	//special cases: removing first node, removing last node, empty list
	if (this->head == NULL || index < 0 || index >= (int) this->current_planets) {
		return false;
	}

	Node * curr = this->head;
	if (index == 0) {
		this->head = this->head->next;
		this->head->prev = NULL;
		this->current_planets --;
		return true;
	}

	if (index == (int) this->current_planets) {
		curr = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		this->current_planets --;
		return true;
	}

	bool ret = false;
	for (int i = 0; curr->next != NULL && i < index; i ++) {
		curr = curr->next;
	}
	ret = true;

	if (ret) {
		Node * prev = curr->prev;
		prev->next = curr->next;
		curr->next->prev = prev;

		this->current_planets --;
	}
	return ret;

}

unsigned List::size() {
	return this->current_planets;
}
