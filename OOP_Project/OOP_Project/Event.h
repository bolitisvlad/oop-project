#pragma once
#include <iostream>
#include <String>

using namespace std;

class Event {
	char* name = nullptr;
	int duration = 0; //in minutes
	string date = ""; // dd-mm-yyyy format

	static int maxYear;
	static int minYear;
public:
	Event(char* name, int duration, string date);

	Event(char* name, int duration);

	Event(const Event& event);

	void setName(char* name);

	void setDuration(int duration);

	void setDate(string date);

	char* getName();

	int getDuration();

	string getDate();

	~Event();

	Event& operator=(Event& event);

	Event operator++();

	Event operator++(int);

	friend ostream& operator<<(ostream& out, Event);
	friend istream& operator>>(istream& in, Event&);
};