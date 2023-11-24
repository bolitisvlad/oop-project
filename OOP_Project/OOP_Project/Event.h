#pragma once

#include <String>

using namespace std;

class Event {
	char* name;
	int duration; //in minutes
	string date; // dd-mm-yyyy format

	static int maxYear;
	static int minYear;
public:
	Event(char* name, int duration, string date);

	Event(Event& event);

	~Event();

	void setName(char* name);

	void setDuration(int duration);

	void setDate(string date);

	char* getName();

	int getDuration();
	string gateDate();
};