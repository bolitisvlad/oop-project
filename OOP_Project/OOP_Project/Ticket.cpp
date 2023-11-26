#include<iostream>
#include"Ticket.h"

Ticket::Ticket(int row, int seat, int noRows, int noSeatsPerRow, vip isVip) {
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
	this->setRows(row);
	this->setSeat(seat);
	this->setVip(isVip);
	if(id == 0)
		this->createRowMatrix();

	this->id++;
}

Ticket::Ticket(int row, int seat, int noRows, int noSeatsPerRow) {
	this->setNoRows(noRows);
	this->setNoSeatsPerRow(noSeatsPerRow);
	this->setRows(row);
	this->setSeat(seat);
	if (id == 0)
		this->createRowMatrix();
	this->id++;
}

Ticket::Ticket(const Ticket& ticket) {
	this->setNoRows(ticket.noRows);
	this->setNoSeatsPerRow(ticket.noSeatsPerRow);
	this->setRows(ticket.row);
	this->setSeat(ticket.seat);
	this->setVip(ticket.isVip);
	this->id++;
}

void Ticket::setRows(int row) {
	if (row > this->noRows)
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

Ticket::~Ticket() {
	if (this->rowMatrix != nullptr) {
		for (int i = 0; i < this->noRows; i++)
			delete[] this->rowMatrix[i];
		delete[] this->rowMatrix;
	}
}

int Ticket::id = 0;
int** Ticket::rowMatrix = nullptr;