#pragma once
#include <iostream>
#include <String>

using namespace std;

class Event {
	string  name;
	int duration = 0; //in minutes
	string date = ""; // dd-mm-yyyy format

	static int maxYear;
	static int minYear;
public:
	Event(string name, int duration, string date);

	Event(string name, int duration);

	Event(const Event& event);

	void setName(string  name);

	void setDuration(int duration);

	void setDate(string date);

	string  getName();

	int getDuration();

	string getDate();

	~Event();

	Event& operator=(Event& event);

	Event& operator+(int value);

	Event operator++();

	Event operator++(int);

	/*bool operator==(Event& event);*/

	operator int();

	bool operator!();

	bool operator>(Event& event);

	friend ostream& operator<<(ostream& out, Event);
	friend istream& operator>>(istream& in, Event&);
};