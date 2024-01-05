#include <iostream>
#include <fstream>

#include "Event.h"
#include "Location.h"
#include "Ticket.h"

using namespace std;

int main() {
	cout << "[1] Use file" << endl << "[2] Use CLI" << endl << "Enter your choise: ";
	int answer;
	cin >> answer;

	string fileName;

	if (answer == 1) {
		cout << "Enter file name: ";
		cin >> fileName;

		ifstream file(fileName);

		if (file.is_open()) {

		}

		file.close();
	}

	if (answer == 2) {

	}
}