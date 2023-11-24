#pragma once

#include <iostream>
#include <string>

using namespace std;

class Location {
	int noRows;
	int noSeatsPerRow;
	char* name;
public:
	Location(char* name, int duration, string date);

	Location(Location& event);

	~Location();

	void setNoRows(int noRows);

	void setNoSeats(int noSeats);

	void setName(char* name);

	int getNoRows();
	int getNoSeats();
};