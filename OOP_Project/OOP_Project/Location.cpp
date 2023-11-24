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

int Location::getNoRows() { return this->noRows; }
int Location::getNoSeats() { return this->noSeatsPerRow; }
