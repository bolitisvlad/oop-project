#pragma once

#include <iostream>
#include <string>

using namespace std;

class Location {
	char* name = nullptr;
	int noRows = 0;
	int noSeatsPerRow = 0;
public:
	Location(char* name, int noRows, int noSeatsPerRow);

	Location(char* name);

	Location(const Location& event);

	void setNoRows(int noRows);

	void setNoSeats(int noSeats);

	void setName(char* name);

	char* getName();

	int getNoRows();

	int getNoSeats();

	Location& operator=(Location& location);

	Location& operator+(int value);

	Location operator++();

	Location operator++(int i);

	operator int();

	friend ostream& operator<<(ostream& out, Location);
	friend istream& operator>>(istream& in, Location&);

	~Location();
};