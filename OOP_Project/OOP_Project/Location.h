#pragma once

#include <iostream>
#include <string>

using namespace std;

class Location {
	int noRows;
	int noSeatsPerRow;
	char* name;
public:
	Location(char* name, int noRows, int noSeatsPerRow);

	Location(Location& event);

	~Location();

	void setNoRows(int noRows);

	void setNoSeats(int noSeats);

	void setName(char* name);

	char* getName();

	int getNoRows();

	int getNoSeats();
};