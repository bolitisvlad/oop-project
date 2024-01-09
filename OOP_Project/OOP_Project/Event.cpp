#include "Event.h"
#include <iostream>
#include <String>

using namespace std;

Event::Event(string  name, int duration, string date) {
	this->setName(name);
	this->setDuration(duration);
	this->setDate(date);
}

Event::Event(string  name, int duration) {
	this->setName(name);
	this->setDuration(duration);
}

Event::Event(const Event& event) {
	this->setName(event.name);;
	this->setDuration(event.duration);
	this->setDate(event.date);
}

void Event::setName(string  name) {
	this->name = name;
}

void Event::setDuration(int duration) {
	if (duration < 0)
		throw exception("Wrong input");
	this->duration = duration;
}

void Event::setDate(string date) { // dd-mm-yyyy format
	if (date != "") {
		int day = atoi(date.substr(0, 2).c_str());
		int month = atoi(date.substr(3, 2).c_str());
		int year = atoi(date.substr(6, 4).c_str());

		if (month > 12 || month < 1)
			throw exception("Wrong input");

		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			throw exception("Wrong input");

		if (month == 2 && year % 4 == 0 && day > 29)
			throw exception("Wrong input");

		if (day > 31 || day < 1)
			throw exception("Wrong input");

		if (year > maxYear || year < minYear)
			throw exception("Wrong input");
	}

	this->date = date;
}

string  Event::getName() {
	return this->name;
}

int Event::getDuration() { return this->duration; }

string Event::getDate() { return this->date; }

Event::~Event() {
}

Event& Event::operator=(Event& event) {
	if (this == &event)
		return *this;

	this->setName(event.name);
	this->setDuration(event.duration);
	this->setDate(event.date);

	return *this;
}

Event& Event::operator+(int value) {
	this->duration += value;

	return *this;
}

Event Event::operator++() {
	this->duration += 60;
	return *this;
}

Event Event::operator++(int) {
	Event copy = *this;
	this->duration += 60;

	return copy;
}

Event::operator int() {
	return duration;
}

bool Event::operator!() {
	if (this->duration < 30)
		return false;
	return true;
}

//bool Event::operator==(Event& event) {
//	for (int i = 0; i < strlen(name) + 1; i++)
//		if (name[i] != event.name[i])
//			return false;
//	return duration == event.duration
//		&& date == event.date;
//}

bool Event::operator>(Event& event) {
	return duration > event.duration;
}

ostream& operator<<(ostream& out, Event event) {
	out << endl << event.name;
	out << endl << event.duration;

	if (event.date != "")
		out << endl << event.date << endl;

	return out;
}

istream& operator>>(istream& in, Event& event) {
	cout << endl << "Enter name: ";
	cin.ignore();
	getline(in, event.name);

	cout << endl << "Enter duration: ";

	int duration;
	in >> duration;

	event.setDuration(duration);

	cout << endl << "Enter date: ";

	string date;
	in >> date;

	event.setDate(date);

	return in;
}

int Event::maxYear = 2999;
int Event::minYear = 1000;