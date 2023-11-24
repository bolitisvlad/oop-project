#pragma once

#include <iostream>

using namespace std;

class Location {
	int noRows;
	int noSeatsPerRow;
public:
	Location(char* name, int duration, string date);

	Location(Location& event);

	void setNoRows(int noRows);

	void setNoSeats(int noSeats);

	int getNoRows();
	int getNoSeats();
};