#include<iostream>
#include"Ticket.h"


Ticket::Ticket(int id, int row, int seat, bool isVip, Location& location) : location(location){
	this->setId(id);
	this->setRow(row);
	this->setSeat(seat);
	this->setVip(isVip);
}

Ticket::Ticket(const Ticket& ticket) : location(ticket.location) {
	this->setId(ticket.id);
	this->setRow(ticket.row);
	this->setSeat(ticket.seat);
	this->setVip(ticket.isVip);
}

void Ticket::setId(int id) {
	this->id = id;
}

void Ticket::setRow(int row){
	this->row = row;
}

void Ticket::setSeat(int seat) {
	this->seat = seat;
}

void Ticket::setVip(bool isVip){
	this->isVip = isVip;
}

int Ticket::getId() { return this->id; }

int Ticket::getRow() { return this->row; }

int Ticket::getSeat() { return this->seat; }

Ticket::~Ticket() {

}