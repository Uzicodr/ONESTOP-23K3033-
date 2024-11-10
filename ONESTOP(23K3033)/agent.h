#pragma once
#include<iostream>
#include "ticket.h"
using namespace std;

class agent {
public:
    static int id;
    int agentid;
    string name;
    int assignedcount;
    bool availibility;
    ticket assigned[5];

    agent(string n) {
        id++;
        agentid = id;
        name = n;
        assignedcount = 0;
        availibility = true;
    }

    agent() {
        id++;
        agentid = id;
        name = "";
        assignedcount = 0;
        availibility = true;
    }

    agent& operator=(const agent& other) {
        if (this != &other) {
            name = other.name;
            assignedcount = other.assignedcount;
            availibility = other.availibility;
            for (int i = 0; i < other.assignedcount; i++) {
                assigned[i] = other.assigned[i];
            }
        }
        return *this;
    }

    bool noticketassigned() {
        return assignedcount == 0;
    }

    void addtickettoagent(ticket t1) {
        if (assignedcount < 5) {
            assigned[assignedcount] = t1;
            assignedcount++;
        }
        if (assignedcount == 5) {
            availibility = false;
        }
    }

    ticket closeticket(int idx) {
        if (idx < 0 || idx >= assignedcount) {
            cout << "Invalid ticket index." << endl;
            return {};
        }

        assigned[idx].closetime = assigned[idx].getCurrentTimestamp();
        ticket temp = assigned[idx];
        temp.status = false;

        for (int i = idx; i < assignedcount - 1; i++) {
            assigned[i] = assigned[i + 1];
        }

        assignedcount--;

        if (assignedcount < 5) {
            availibility = true;
        }

        cout << "Ticket closed and removed from agent's assigned list." << endl;
        return temp;
    }

    void displayassigned() {
        for (int i = 0; i < assignedcount; i++) {
            cout << i + 1 << ". ";
            assigned[i].displayticket();
        }
    }

    bool isavailable() {
        return availibility;
    }
};

int agent::id = 0;

class agentmanager {
public:
    agent** ptr;
    int curragents;
    int maxagents;

    agentmanager() {
        ptr = NULL;
        curragents = 0;
        maxagents = 0;
    }

    ~agentmanager() {
        for (int i = 0; i < curragents; i++) {
            delete ptr[i];
        }
        delete[] ptr;
    }

    void addagent(string name) {
        maxagents++;
        agent** newptr = new agent * [maxagents];

        for (int i = 0; i < curragents; i++) {
            newptr[i] = ptr[i];
        }

        newptr[curragents] = new agent(name);

        delete[] ptr;
        ptr = newptr;
        curragents++;
        cout << "New Agent added Successfully" << endl;
    }

    agent* findavailableagent() {
        agent* selected = nullptr;
        int minassigned = INT_MAX;

        for (int i = 0; i < curragents; i++) {
            if (ptr[i]->isavailable() && ptr[i]->assignedcount < minassigned) {
                selected = ptr[i];
                minassigned = ptr[i]->assignedcount;
            }
        }
        return selected;
    }

    bool assignticket(ticket t) {
        agent* selected = findavailableagent();

        if (selected != NULL) {
            selected->addtickettoagent(t);
            cout << "ticket assigned to agent: " << selected->name << endl;
            return true;
        }
        else {
            cout << "no available agents to assign the ticket. Added to queue" << endl;
            return false;
        }
    }

    bool checkavailabilityforall() {
        for (int i = 0; i < curragents; i++) {
            if (ptr[i]->isavailable()) {
                return true;
            }
        }
        return false;
    }

    void displayallagents() {
        for (int i = 0; i < curragents; i++) {
            cout << "--------------------------------------" << endl;
            cout << "Agent #" << i + 1 << endl;
            cout << "--------------------------------------" << endl;
            cout << "Agent ID      : " << ptr[i]->agentid << endl;
            cout << "Name          : " << ptr[i]->name << endl;
            cout << "Assigned Count: " << ptr[i]->assignedcount << endl;
            cout << "Availability  : " << (ptr[i]->availibility ? "Available" : "Unavailable") << endl;

            if (ptr[i]->assignedcount == 0) {
                cout << "Tickets Assigned: 0" << endl;
            }
            else {
                cout << "Tickets Assigned:" << endl;
                ptr[i]->displayassigned();
            }
            cout << "--------------------------------------" << endl;
            cout << endl;
        }
    }

    void displayavailibility() {
        for (int i = 0; i < curragents; i++) {
            if (ptr[i]->availibility) {
                cout << "agent id: " << ptr[i]->agentid << " name: " << ptr[i]->name
                    << " assigned count: " << ptr[i]->assignedcount
                    << " availability: " << (ptr[i]->availibility ? "available" : "unavailable") << endl;
            }
        }
    }

    bool allnotickets() {
        for (int i = 0; i < curragents; i++) {
            if (!ptr[i]->noticketassigned()) {
                return false;
            }
        }
        return true;
    }

    int partition(int low, int high) {
        agent* pivot = ptr[low];
        int i = low, j = high;

        while (i < j) {
            while (i <= high && ptr[i]->assignedcount <= pivot->assignedcount) i++;
            while (j >= low && ptr[j]->assignedcount > pivot->assignedcount) j--;
            if (i < j) {
                agent* temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }

        ptr[low] = ptr[j];
        ptr[j] = pivot;
        return j;
    }

    void quicksort(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            quicksort(low, pivotIndex - 1);
            quicksort(pivotIndex + 1, high);
        }
    }

    void sortagents() {
        quicksort(0, curragents - 1);
        cout << "Agents sorted by assigned count." << endl;
        for (int i = 0; i < curragents; i++) {
            cout << ptr[i]->name << ", Assigned: " << ptr[i]->assignedcount << endl;
        }
    }
};
