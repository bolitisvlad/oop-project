#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(char* name,int noRows, int noSeatsPerRow) {
	this->setName(name);
	this->setNoRows(noRows);
	this->setNoSeats(noSeatsPerRow);
}

Location::Location(char* name) {
	this->setName(name);
}

Location::Location(Location& event) {
	this->setName(name);
	this->setNoRows(event.noRows);
	this->setNoSeats(event.noSeatsPerRow);
}
void Location::setNoRows(int noRows) {
	if (noRows < 1)
		throw exception("Wrong input");
	this->noRows = noRows;
}

void Location::setNoSeats(int noSeats) {
	if (noSeats < 1)
		throw exception("Wrong input");
	this->noSeatsPerRow = noSeats;
}

void Location::setName(char* name) {
	if (name == nullptr)
		throw exception("Wrong input");

	if (this->name != nullptr)
		delete[] this->name;

	this->name = new char[strlen(name) + 1];
	
	strcpy_s(this->name, strlen(name) + 1, name);
}

char* Location::getName() {
	char* nameCopy;
	nameCopy = new char[strlen(this->name) + 1];

	strcpy_s(nameCopy, strlen(this->name) + 1, name);

	return nameCopy;
}

int Location::getNoRows() { return this->noRows; }

int Location::getNoSeats() { return this->noSeatsPerRow; }

Location::~Location() {
	delete[] this->name;
}