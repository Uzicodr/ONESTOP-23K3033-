#pragma once
#include<iostream>
#include<iomanip>   //for good formating
#include <chrono>   //for real timestamp
#include <ctime>    // For converting to calendar time
#include <string>
using namespace std;

class ticket
{
	public:
	static int id;
	int ticketid;
	string name;
	int priority;
	string description;
	string creationtime;
	bool status;
	string closetime;

	public:
		ticket() {
			id++;
			ticketid = id;
			name = "";
			priority = 0;
			description = "";
			creationtime = getCurrentTimestamp();
			status = true;
			closetime = "Nil";
		}
		ticket(string n, int p, string d) {
			id++;
			ticketid = id;
			name = n;
			priority = p;
			description = d;
			creationtime = getCurrentTimestamp();
			closetime = "Nil";
			status = true;
		}

		ticket& operator=(const ticket& other) {
        if (this != &other) {
            ticketid = other.ticketid;
            name = other.name;
            description = other.description;
            creationtime = other.creationtime;
            closetime = other.closetime;
            priority = other.priority;
            status = other.status;
			}
        return *this;
		}

		void displayticket() {
			cout << left << setw(15) << "ID:" << ticketid << endl;
			cout << left << setw(15) << "Name:" << name << endl;
			cout << left << setw(15) << "Priority:" << priority << endl;
			cout << left << setw(15) << "Description:" << description << endl;
			cout << left << setw(15) << "Creation Time:" << creationtime << endl;
			cout << left << setw(15) << "Status:" << (status ? "Open" : "Closed") << endl;
			cout << left << setw(15) << "Close Time:" << (status ? "N/A" : closetime) << endl;
			cout << endl;
		}

		string getCurrentTimestamp() {
			auto now = chrono::system_clock::now();
			time_t currentTime = chrono::system_clock::to_time_t(now);
			tm localTime;
			localtime_s(&localTime, &currentTime);
			char timeString[20];
			strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &localTime);
			return string(timeString);
		}
};

int ticket::id = 0;