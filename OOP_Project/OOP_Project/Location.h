#pragma once

using namespace std;

class Location {
	int noRows;
	int noSeatsPerRow;
public:
	Location(char* name, int duration, string date) {
		this->setNoRows(noRows);
		this->setNoSeats(noSeatsPerRow);
	}

	Location(Location& event) {
		this->setNoRows(event.noRows);
		this->setNoSeats(event.noSeatsPerRow);
	}
	void setNoRows(int noRows) {
		if (noRows < 1)
			throw exception("Wrong input");
		this->noRows = noRows;
	}

	void setNoSeats(int noSeats) {
		if (noSeats < 1)
			throw exception("Wrong input");
		this->noSeatsPerRow = noSeats;
	}

	int getNoRows() { return this->noRows; }
	int getNoSeats() { return this->noSeatsPerRow; }
};