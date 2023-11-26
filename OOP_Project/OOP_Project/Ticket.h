#pragma once
#include <iostream>
#include "Location.h"

using namespace std;

enum vip {
	Default = 0,
	VIP = 1
};

class Ticket{
	static int id;
	int row = 0;
	int seat = 0;
	int noRows = 0;
	int noSeatsPerRow = 0;
	vip isVip = Default;
	static int** rowMatrix;
public:
	Ticket(int row, int seat, int noRows, int noSeatsPerRow, vip isVip);

	Ticket(int row, int seat, int noRows, int noSeatsPerRow);

	Ticket(const Ticket& ticket);

	void setRows(int row);

	void setSeat(int seat);

	void setNoRows(int noRow);

	void setNoSeatsPerRow(int noSeatsPerRow);

	void setVip(vip);

	int getId();

	int getNoRow();

	int getNoSeatsPerRow();

	void createRowMatrix();

	~Ticket();
};