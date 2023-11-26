#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(char* name,int noRows, int noSeatsPerRow) {
	this->setName(name);
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
}

Location::Location(char* name) {
	this->setName(name);
}

Location::Location(const Location& location) {
	this->setName(location.name);
	this->setNoRows(location.noRows);
	this->setNoSeatsPerRow(location.noSeatsPerRow);
}

void Location::setNoRows(int noRows) {
	if (noRows < 1)
		throw exception("Wrong input");
	this->noRows = noRows;
}

void Location::setNoSeatsPerRow(int noSeats) {
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

int Location::getNoSeatsPerRow() { return this->noSeatsPerRow; }

Location& Location::operator=(Location& location) {
	if (this == &location)
		return *this;

	this->setName(location.name);
	this->setNoRows(location.noRows);
	this->setNoSeatsPerRow(location.noSeatsPerRow);

	return *this;
}

Location& Location::operator+(int value) {
	this->noSeatsPerRow += value;

	return *this;
}

Location Location::operator++() {
	this->noSeatsPerRow++;

	return *this;
}

Location Location::operator++(int i) {
	Location copy = *this;
	this->noSeatsPerRow++;
	
	return copy;
}

Location::operator int(){
	return this->noRows;
}

bool Location::operator!() {
	if (this->noSeatsPerRow < 10)
		return false;
	return true;
}

bool Location::operator==(Location& location) {
	for (int i = 0; i < strlen(name) + 1; i++)
		if (name[i] != location.name[i])
			return false;
	return noRows == location.noRows
		&& noSeatsPerRow == location.noSeatsPerRow;
}

bool Location::operator>(Location& location) {
	return noRows > location.noRows;
}

ostream& operator<<(ostream& out, Location location) {
	out << endl << location.name;
	out << endl << location.noRows;
	out << endl << location.noSeatsPerRow;

	return out;
}

istream& operator>>(istream& in, Location& location) {
	cout << endl << "Enter name: ";
	string name;
	getline(in, name);

	if (location.name != nullptr)
		delete[] location.name;

	location.name = new char[strlen(name.c_str()) + 1];
	strcpy_s(location.name, strlen(name.c_str()) + 1, name.c_str());

	cout << endl << "Enter number of rows: ";
	in >> location.noRows;

	cout << endl << "Enter number of seats per row: ";
	in >> location.noSeatsPerRow;

	return in;
}

Location::~Location() {
	delete[] this->name;
}