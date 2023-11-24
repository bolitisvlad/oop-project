#include "Event.h"
#include <iostream>

using namespace std;

Event::Event(char* name, int duration, string date) {
	this->setName(name);
	this->setDuration(duration);
	this->setDate(date);
}

Event::Event(Event& event) {
	this->setName(event.name);;
	this->setDuration(event.duration);
	this->setDate(event.date);
}

Event::~Event() {
	delete[] name;
}

void Event::setName(char* name) {
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
	int day = atoi(date.substr(0, 2).c_str());
	int month = atoi(date.substr(3, 5).c_str());
	int year = atoi(date.substr(6, 8).c_str());

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

	this->date = date;
}

char* Event::getName() {
	char* nameCopy;
	nameCopy = new char[strlen(this->name) + 1];

	strcpy_s(nameCopy, strlen(this->name) + 1, name);

	return nameCopy;
}

int Event::getDuration() { return this->duration; }
string Event::gateDate() { return this->date; }

int Event::maxYear = 2100;
int Event::minYear = 1000;