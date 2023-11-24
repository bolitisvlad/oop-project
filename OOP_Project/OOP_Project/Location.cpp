#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(char* name, int duration, string date) {
	this->setNoRows(noRows);
	this->setNoSeats(noSeatsPerRow);
}

Location::Location(Location& event) {
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
	for (int i = 0; i < strlen(name) + 1; i++)
		this->name[i] = name[i];
}

Location::~Location() {
	delete[] this->name;
}

int Location::getNoRows() { return this->noRows; }
int Location::getNoSeats() { return this->noSeatsPerRow; }
