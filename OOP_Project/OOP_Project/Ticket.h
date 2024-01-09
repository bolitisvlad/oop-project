#pragma once
#include <iostream>

using namespace std;

class Ticket{
	int id = 0;
	int row = 0;
	int seat = 0;
	bool isVip;
public:
	Ticket(int id, int row, int seat, bool isVip);

	Ticket(const Ticket& ticket);

	void setId(int id);

	void setRow(int row);

	void setSeat(int seat);

	void setVip(bool isVip);

	int getId();

	int getRow();

	int getSeat();

	~Ticket();
};