#include <iostream>
#include <fstream>
#include <string>

#include "Event.h"
#include "Location.h"
#include "Ticket.h"

using namespace std;

void displayMenu() {
	cout << "[1] Create Location\n";
	cout << "[2] Create Event\n";
	cout << "[3] Create Ticket\n";
	cout << "[4] Exit\n";
}

int main(int argc, char* argv[]) {
	if (argc == 2) {

	}

	else {
		int choice;

		do {
			displayMenu();

			cout << "Enter your choise: ";
			cin >> choice;

			switch (choice)
			{
			case 1: {}

			case 2: {}

			case 3: {}
			}

		} while (choice != 4);
	}
}