#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(string name,int noRows, int noSeatsPerRow, vector<int> vipRows) : layout(noRows, vector<int>(noSeatsPerRow, 0)) {
	this->setName(name);
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
	this->setVipRows(vipRows);
}

Location::Location(string name) {
	this->setName(name);
}

Location::Location(const Location& location) : layout(location.noRows, vector<int>(location.noSeatsPerRow, 0)) {
	this->setName(location.name);
	this->setNoRows(location.noRows);
	this->setNoSeatsPerRow(location.noSeatsPerRow);
	this->setVipRows(location.vipRows);
}

void Location::setVipRows(vector<int> vipRows) {
	for (int i : vipRows) {
		if (i < 0)
			throw exception("Wrong Input");
		if(i > this->noRows)
			throw exception("Wrong Input");
	}

	this->vipRows = vipRows;
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

void Location::setName(string name) {
	this->name = name;
}

string Location::getName() {
	return this->name;
}

int Location::getNoRows() { return this->noRows; }

int Location::getNoSeatsPerRow() { return this->noSeatsPerRow; }

void Location::printVect() {
	for (int i = 0; i < layout.size(); i++)
	{
		for (int j = 0; j < layout[i].size(); j++)
		{
			cout << layout[i][j] << " ";
		}
		cout << endl;
	}
}

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


bool Location::operator>(Location& location) {
	return noRows > location.noRows;
}

ostream& operator<<(ostream& out,Location location) {
	out << endl << location.name;
	out << endl << location.noRows;
	out << endl << location.noSeatsPerRow;
	for (int element : location.vipRows)
		out << endl << element;
	return out;
}

istream& operator>>(istream& in, Location& location) {
	cout << endl << "Enter name: ";
	cin.ignore();
	getline(in, location.name);

	cout << endl << "Enter number of rows: ";
	in >> location.noRows;

	cout << endl << "Enter number of seats per row: ";
	in >> location.noSeatsPerRow;

	int nr;
	
	cout << endl << "Enter the number of vip rows: ";
	cin >> nr;
	int input;
	for (int i = 0; i < nr; i++) {
		cout << endl << "Enter the row number: ";
		cin >> input;
		for (int j : location.vipRows) {
			if (j == input)
				throw exception("Wrong input");
		}
		location.vipRows.push_back(input);
	}

	return in;
}

Location::~Location() {
}