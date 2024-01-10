#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Location {
	string name;
	int noRows = 0;
	int noSeatsPerRow = 0;
	int noVip = 0;

	vector<vector<int>> layout;

	vector<int> vipRows;

public:

	Location(string name, int noRows, int noSeatsPerRow, int noVip, vector<int> vipRows);

	Location(string name);

	Location(const Location& location);

	void setVipRows(vector<int> vipRows);

	void setNoRows(int noRows);

	void setNoSeatsPerRow(int noSeats);

	void setName(string name);

	string getName();

	int getNoRows();

	int getNoSeatsPerRow();

	void printVect();

	Location& operator=(Location& location);

	Location& operator+(int value);

	Location operator++();

	Location operator++(int i);

	operator int();

	bool operator!();

	bool operator>(Location& location);

	friend ostream& operator<<(ostream& out, Location);
	friend istream& operator>>(istream& in, Location&);

	~Location();
};