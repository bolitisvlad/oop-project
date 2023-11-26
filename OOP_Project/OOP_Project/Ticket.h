#pragma once
#include <iostream>

using namespace std;

enum vip {
	Default = 0,
	VIP = 1
};

class Ticket{
	int id = 0;
	int row = 0;
	int seat = 0;
	int noRows = 0;
	int noSeatsPerRow = 0;
	vip isVip = Default;
	const int vipRowAray[3] = {3,4,5};
	static int** rowMatrix;
	static int noId;
public:
	Ticket(int id, int row, int seat, int noRows, int noSeatsPerRow, vip isVip);

	Ticket(int id, int row, int seat, int noRows, int noSeatsPerRow);

	Ticket(const Ticket& ticket);

	void setId(int id);

	void setRows(int row);

	void setSeat(int seat);

	void setNoRows(int noRow);

	void setNoSeatsPerRow(int noSeatsPerRow);

	void setVip(vip);

	int getId();

	int getNoRow();

	int getNoSeatsPerRow();

	void createRowMatrix();

	void fillRowMatrix();

	Ticket& operator=(Ticket& ticket);

	Ticket& operator+(int value);

	Ticket operator++();

	Ticket operator++(int);

	operator int();

	bool operator==(Ticket& ticket);

	bool operator>(Ticket& ticket);


	friend ostream& operator<<(ostream& out, Ticket);
	friend istream& operator>>(istream& in, Ticket&);

	~Ticket();
};