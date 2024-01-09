#pragma once
#include <iostream>
#include "Location.h"

using namespace std;

class Ticket{
	int id = 0;
	int row = 0;
	int seat = 0;
	bool isVip;

	Location& location;
public:
	Ticket(int id, int row, int seat, bool isVip, Location& location);

	Ticket(const Ticket& ticket);

	void setId(int id);

	void setRow(int row);

	void setSeat(int seat);

	void setVip(bool isVip);

	int getId();

	int getRow();

	int getSeat();

	friend ostream& operator<<(ostream& out, Ticket);

	friend istream& operator>>(istream& in, Ticket&);

	~Ticket();
};