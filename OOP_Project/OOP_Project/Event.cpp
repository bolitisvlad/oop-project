#include "Event.h"
#include <iostream>
#include <String>

using namespace std;

Event::Event(char* name, int duration, string date) {
	this->setName(name);
	this->setDuration(duration);
	this->setDate(date);
}

Event::Event(char* name, int duration) {
	this->setName(name);
	this->setDuration(duration);
}

Event::Event(Event& event) {
	this->setName(event.name);;
	this->setDuration(event.duration);
	this->setDate(event.date);
}

void Event::setName(char* name) {
	if (strlen(name) < 1)
		throw exception("Wrong input");

	if (this->name != nullptr)
		delete[] this->name;
	this->name = new char[strlen(name) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);
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

char* Event::getName() {
	char* nameCopy;
	nameCopy = new char[strlen(this->name) + 1];

	strcpy_s(nameCopy, strlen(this->name) + 1, name);

	return nameCopy;
}

int Event::getDuration() { return this->duration; }

string Event::getDate() { return this->date; }

Event::~Event() {
	delete[] this->name;
}

Event& Event::operator=(Event& event) {
	if (this == &event)
		return *this;

	this->setName(event.name);
	this->setDuration(event.duration);
	this->setDate(event.date);

	return *this;
}

Event Event::operator++() {
	this->duration += 60;
	return *this;
}

Event Event::operator++(int) {
	Event copy = *this;
	this->duration += 60;

	return *this;
}

ostream& operator<<(ostream& out, Event event) {
	out << event.name << endl;
	out << event.duration << endl;

	if (event.date != "")
		out << event.date << endl;

	return out;
}

istream& operator>>(istream& in, Event& event) {
	cout << endl << "Enter name: ";
	string name;
	getline(in, name);

	if (event.name != nullptr)
		delete[] event.name;

	event.name = new char[name.length() + 1];
	strcpy_s(event.name, name.length() + 1, name.c_str());

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

int Event::maxYear = 2100;
int Event::minYear = 1000;