#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Event.h"
#include "Location.h"
#include "Ticket.h"

using namespace std;

void displayMenu() {
	cout << endl;
	cout << "[1] Create Location\n";
	cout << "[2] Create Event\n";
	cout << "[3] Buy Ticket\n";
	cout << "[4] Exit\n";
}

int main(int argc, char* argv[]) {
	if (argc == 2) {

	}

	int choice;

	vector<Location> locations;
	vector<Event> events;
	vector<Ticket> tickets;

	do {
		try
		{
			displayMenu();

			cout << "Enter your choise: ";
			cin >> choice;

			switch (choice)
			{
			case 1: {
				Location location("Default");
				cin >> location;
				locations.push_back(location);
				for (const Location& l : locations) {
					cout << l << endl;
				}
				break;
			}

			case 2: {
				Event event("Default", 0);
				cin >> event;
				cout << event;
				events.push_back(event);
				break;
			}

			case 3: {
				if (locations.empty()) {
					cout << "\nNo locations available \n";
					break;
				}
				Ticket ticket(0, 0, 0, 0, locations[0]);
				cin >> ticket;
				break;
			}

			default:
				if (choice != 4) {
					cout << "\nWrong input\n";
				}
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "\nWrong input! Try again: \n";
		}

	} while (choice != 4);
}