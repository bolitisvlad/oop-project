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

	Location(Location& event);

	~Location();

	void setNoRows(int noRows);

	void setNoSeats(int noSeats);

	void setName(char* name);

	char* getName();

	int getNoRows();

	int getNoSeats();
};