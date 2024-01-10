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

	vector<Location> locations;
	vector<Event> events;
	vector<Ticket> tickets;

	int choice;

	if (argc == 2) {
		string filename = argv[1];
		ifstream File(filename);
		if (File.is_open()) {
			while (File >> choice) {
				try {
					switch (choice)
					{
					case 1: {
						string name;
						int noRows;
						int noSeatPerRow;
						int noVip;
						bool isVip;

						getline(File >> ws, name);

						File >> noRows;
						File >> noSeatPerRow;
						File >> noVip;

						int temp;

						vector<int> vip;
						for (int i = 0; i < noVip; i++) {
							File >> temp;
							vip.push_back(temp);
						}

						for (int i = 0; i < noVip; i++) {
							for (int j = i + 1; j < noVip; j++)
								if (vip[i] == vip[j])
									throw exception();
						}

						Location location(name, noRows, noSeatPerRow,noVip, vip);

						locations.push_back(location);

						break;
					}

					case 2: {
						string name;
						int duration;
						string date;

						getline(File >> ws, name);
						File >> duration;
						getline(File >> ws, date);

						Event event(name, duration, date);

						events.push_back(event);
						break;
					}

					case 3: {
						if (locations.empty()) {
							cout << "\nNo locations available \n";
							break;
						}

						int id;
						int row;
						int seat;
						bool isVip;

						File >> id;
						File >> row;
						File >> seat;
						File >> isVip;

						Ticket ticket(id, row, seat, isVip, locations[0]);
						
						tickets.push_back(ticket);

						/*ofstream ticketsFile("Tickets.bin", ios::app | ios::binary | ios::out);

						ticketsFile.write((char*)ticket.getId(), sizeof(int));
						ticketsFile.write((char*)ticket.getRow(), sizeof(int));
						ticketsFile.write((char*)ticket.getSeat(), sizeof(int));
						ticketsFile.write((char*)ticket.getVip(), sizeof(bool));

						ticketsFile.close();*/
						break;
					}

					default:
						if (choice != 4) {
							cout << "\nWrong input\n";
						}
						break;
					}
				}
				catch (const exception&)
				{
					cout << "\nWrong input!\n";
				}
			}
			if (!locations.empty()) {
				for (const Location& l : locations) {
					cout << l << endl;
				}
			}
			if (!events.empty()) {
				for (const Event& e : events) {
					cout << e << endl;
				}
			}
		}
	}
	else {
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

					tickets.push_back(ticket);

					/*ofstream ticketsFile("Tickets.bin", ios::app | ios::binary | ios::out);

					ticketsFile.write((char*)ticket.getId(), sizeof(int));
					ticketsFile.write((char*)ticket.getRow(), sizeof(int));
					ticketsFile.write((char*)ticket.getSeat(), sizeof(int));
					ticketsFile.write((char*)ticket.getVip(), sizeof(bool));*/

					break;
				}

				default:
					if (choice != 4) {
						cout << "\nWrong input\n";
					}
					break;
				}
			}
			catch (const exception&)
			{
				cout << "\nWrong input! Try again: \n";
			}

		} while (choice != 4);
	}
	ofstream locationsFile("Locations.txt", ios::app);

	if (!locations.empty()) {
		for (const Location& l : locations) {
			locationsFile << l << endl;
		}
	}

	ofstream eventsFile("Events.txt", ios::app);

	if (!events.empty()) {
		for (const Event& e : events) {
			eventsFile << e << endl;
		}
	}

	locationsFile.close();
	eventsFile.close();
	//ticketsFile.close();
}