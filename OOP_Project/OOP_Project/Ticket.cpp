#include<iostream>
#include"Ticket.h"

Ticket::Ticket(int id, int row, int seat, int noRows, int noSeatsPerRow, vip isVip) {
	this->setId(id);
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
	this->setVip(isVip);
	this->setRows(row);
	this->setSeat(seat);
	if(this->rowMatrix == nullptr)
		this->createRowMatrix();
	this->fillRowMatrix();
}

Ticket::Ticket(int id, int row, int seat, int noRows, int noSeatsPerRow) {
	this->setId(id);
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
	this->setRows(row);
	this->setSeat(seat);
	if (id == 1)
		this->createRowMatrix();
	this->fillRowMatrix();
}

Ticket::Ticket(const Ticket& ticket) {
	this->setId(ticket.id);
	this->setNoRows(ticket.noRows);
	this->setNoSeatsPerRow(ticket.noSeatsPerRow);
	this->setVip(ticket.isVip);
	this->setRows(ticket.row);
	this->setSeat(ticket.seat);
	this->fillRowMatrix();
}

void Ticket::setId(int id) {
	if (id < 0)
		throw exception("Wrong input");
	this->id = id;
}

void Ticket::setRows(int row) {
	if (row > this->noRows)
		throw exception("Wrong input");
	for (int i = 0; i < 3; i++)
		if (row == this->vipRowAray[i] && this->isVip == Default)
			throw exception("Wrong input");
	this->row = row;
}

void Ticket::setSeat(int seat) {
	if (seat > this->noSeatsPerRow)
		throw exception("Wrong input");
	this->seat = seat;
}

void Ticket::setNoRows(int noRow) {
	this->noRows = noRow;
}

void Ticket::setNoSeatsPerRow(int noSeatsPerRow) {
	this->noSeatsPerRow = noSeatsPerRow;
}

void Ticket::setVip(vip value) {
	this->isVip = value;
}

int Ticket::getNoRow() {
	return this->noRows;
}

int Ticket::getNoSeatsPerRow() {
	return this->noSeatsPerRow;
}

int Ticket::getId() {
	return this->id;
}

void Ticket::createRowMatrix() {
	if (this->rowMatrix != nullptr) {
		for (int i = 0; i < this->noRows; i++)
			delete[] this->rowMatrix[i];
		delete[] this->rowMatrix;
	}

	this->rowMatrix = new int*[this->noRows];
	for (int i = 0; i < this->noRows; i++)
		this->rowMatrix[i] = new int[this->noSeatsPerRow];

	for (int i = 0; i < this->noRows; i++)
		for (int j = 0; j < this->noSeatsPerRow; j++)
			rowMatrix[i][j] = 0;
}

void Ticket::fillRowMatrix() {
	rowMatrix[this->row][this->seat] = 1;
}

Ticket& Ticket::operator=(Ticket& ticket) {
	if (this == &ticket)
		return *this;

	this->setId(ticket.id);
	this->setVip(ticket.isVip);
	this->setNoRows(ticket.noRows);
	this->setNoSeatsPerRow(ticket.noSeatsPerRow);
	this->setRows(ticket.row);
	this->setSeat(ticket.seat);

	return *this;
}

Ticket& Ticket::operator+(int value) {
	this->noRows++;

	return *this;
}

Ticket Ticket::operator++() {

	if (this->isVip == vip::Default)
		this->setVip(vip::VIP);
	else(this->setVip(vip::Default));

	return *this;
}

Ticket Ticket::operator++(int) {
	Ticket copy = *this;

	if (this->isVip == vip::Default)
		this->setVip(vip::VIP);

	return copy;
}

Ticket::operator int() {
	return id;
}

bool Ticket::operator==(Ticket& ticket) {
	return id == ticket.id
		&& noRows == ticket.noRows
		&& noSeatsPerRow == ticket.noSeatsPerRow
		&& isVip == ticket.isVip
		&& row == ticket.row
		&& seat == ticket.seat;
}

bool Ticket::operator>(Ticket& ticket) {
	return row > ticket.row;
}

ostream& operator<<(ostream& out, Ticket ticket) {
	out << endl << "Ticket id:" << ticket.id;
	out << endl << "Ticket row: " << ticket.row;
	out << endl << "Ticket seat: " << ticket.seat;
	out << endl << "Ticket total rows: " << ticket.noRows;
	out << endl << "Ticket seats pear row: " << ticket.noSeatsPerRow;
	if (ticket.isVip == 0)
		out << endl << "Ticket type: " << "Default";
	else out << endl << "Ticket type: " << "VIP";
	out << endl << "VIP rows: ";
	for(int i = 0; i < 3; i++)
		out << ticket.vipRowAray[i] << " ";

	return out;
}

istream& operator>>(istream& in, Ticket& ticket) {
	cout << endl << "Enter id: ";
	in >> ticket.id;

	cout << endl << "Enter the number of rows: ";
	in >> ticket.noRows;

	cout << endl << "Enter the number of seats per row: ";
	in >> ticket.noSeatsPerRow;

	cout << endl << "Enter row: ";
	in >> ticket.row;

	cout << endl << "Enter seat: ";
	in >> ticket.seat;

	cout << endl << "vip(0 = Not VIP/ 1 = VIP): ";
	int i = 0;
	in >> i;

	if (i != 0 && i != 1)
		throw exception("Wrong input");

	if (i == 0)
		ticket.isVip = vip::Default;
	else ticket.isVip = vip::VIP;

	return in;
}

Ticket::~Ticket() {

}

int** Ticket::rowMatrix = nullptr;