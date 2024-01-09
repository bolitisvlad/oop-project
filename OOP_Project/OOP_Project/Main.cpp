#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Event.h"
#include "Location.h"
#include "Ticket.h"

using namespace std;

void displayMenu() {
	cout << "[1] Create Location\n";
	cout << "[2] Create Event\n";
	cout << "[3] Buy Ticket\n";
	cout << "[4] Exit\n";
}

int main(int argc, char* argv[]) {
	if (argc == 2) {

	}

	int choice;
	do {
		displayMenu();

		cout << "Enter your choise: ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			Location location("Default");
			cin >> location;
			break;
		}

		case 2: {
			break;
		}

		case 3: {
			break;
		}

		default:
			if (choice != 4) {
				cout << "\nWrong input\n";
			}
			break;
		}

	} while (choice != 4);
}