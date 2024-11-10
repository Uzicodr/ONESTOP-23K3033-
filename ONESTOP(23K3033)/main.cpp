#include<iostream>
#include<windows.h>  //for sleep func(delay)
#include"linkedlist.h"
#include"ticket.h"
#include "agent.h"
#include "logged_stack.h"
#include "Pendingqueue.h"

using namespace std;

static int agentidx = 5;

int main() {
    cout << "23k3033-UZAIR HAROON" << endl;

    ticket t1("Uzair Haroon", 2, "Accounts");
    ticket t2("Umair Haroon", 1, "Transport");
    ticket t4("Mr Haroon", 3, "Acedemics");
    ticket t3("Mr Lonely", 3, "IT");
    ticket t5("Uxair Haroon", 2, "Accounts");
    ticket t6("Umro Haroon", 1, "Transport");
    ticket t7("Islam", 3, "Acedemics");
    ticket t8("Alex Perriera", 3, "IT");

    ll tickets;
    logged_stack pasttickets;
    Pendingqueue q1;
    Pendingqueue q2;
    Pendingqueue q3;

    q1.enqueue(t2);
    q2.enqueue(t1);
    q3.enqueue(t3);
    q3.enqueue(t4);
    q1.enqueue(t1);
    q2.enqueue(t5);
    q3.enqueue(t7);
    q3.enqueue(t8);

    agentmanager allagents;
    allagents.addagent("Mr Ali");
    allagents.addagent("Mr Shahzaib");
    allagents.addagent("Mr Hashir");
    allagents.addagent("Mr Hadi");
    allagents.addagent("Mr Umer");
    allagents.addagent("Mr Jamshed");

    tickets.insertattail(t3);
    tickets.insertattail(t2);
    tickets.insertattail(t1);
    tickets.insertattail(t4);

    do {
        cout << "ONESTOP BY FASTIAN ;)" << endl;
        cout << "\t1. Add ticket" << endl;
        cout << "\t2. Remove ticket" << endl;
        cout << "\t3. Search ticket" << endl;
        cout << "\t4. Sort tickets" << endl;
        cout << "\t5. Add agent" << endl;
        cout << "\t6. Assign agent" << endl;
        cout << "\t7. Show Agent status" << endl;
        cout << "\t8. Show pending tickets" << endl;
        cout << "\t9. Show closed tickets " << endl;
        cout << "\t10. Show Open tickets " << endl;
        cout << "\t11. Show all tickets " << endl;
        cout << "\t12. Close a ticket " << endl;
        cout << "\t13. Sort Agents " << endl;
        cout << "\t14. Sort with config settings " << endl;
        cout << "\t15. Exit" << endl;

        int ch;
        cout << "Enter Your Choice:";
        cin >> ch;
        switch (ch) {
        case 1: {
            int priority, d;
            string name, dept;
            cout << "Enter name:";
            cin >> name;
            cout << "Choose desired department of concern:\t1.Accounts\t2.IT\t3.Transport\t4.Academics" << endl;
            cin >> d;
            if (d < 1 || d > 4) {
                cout << "Invalid department selected" << endl;
                Sleep(5000);
                system("cls");
                break;
            }

            switch (d) {
            case 1: dept = "Accounts"; break;
            case 2: dept = "IT"; break;
            case 3: dept = "Transport"; break;
            case 4: dept = "Academics"; break;
            }

            cout << "Enter priority:";
            cin >> priority;
            if (priority < 1 || priority > 3) {
                cout << "Invalid priority selected" << endl;
                Sleep(5000);
                system("cls");
                break;
            }

            ticket newticket(name, priority, dept);
            tickets.insertattail(newticket);

            if (allagents.assignticket(newticket)) {
                cout << "YOUR TICKET DETAILS:" << endl;
                newticket.displayticket();
            }
            else {
                if (newticket.priority == 1)
                    q1.enqueue(newticket);
                else if (newticket.priority == 2)
                    q2.enqueue(newticket);
                else if (newticket.priority == 3)
                    q3.enqueue(newticket);
            }
            Sleep(5000);
            system("cls");
            break;
        }

        case 2: {
            int id;
            cout << "Enter id to remove:";
            cin >> id;
            if (tickets.searchidx(id)==-1) {
                cout << "Ticket not found" << endl;
            }
            else {
                tickets.deleteatkth(id);
                cout << "Deleted!!" << endl;
            }
            Sleep(5000);
            system("cls");
            break;
        }

        case 3: {
            int id;
            cout << "Enter id to search:";
            cin >> id;

            ticket temp = tickets.searchid(id);
            if (temp.name == "") {
                cout << "Ticket not found" << endl;
            }
            else {                
                temp.displayticket();
            }
            Sleep(5000);
            system("cls");
            break;
        }

        case 4: {
            cout << "\t1.Bubble Sort" << endl;
            cout << "\t2.Insertion Sort" << endl;
            cout << "\t3.Selection Sort" << endl;
            cout << "\t4.Merge Sort" << endl;
            cout << "\t5.Quick Sort" << endl;

            int c;
            cin >> c;
            if (c < 1 || c > 5) {
                cout << "Invalid sorting option" << endl;
                Sleep(5000);
                system("cls");
                break;
            }

            switch (c) {
            case 1: tickets.bubblesort_priority(); break;
            case 2: tickets.insertionsort_priority(); break;
            case 3: tickets.selectionsort_priority(); break;
            case 4: tickets.mergesort(tickets.gethead()); break;
            case 5: tickets.quicksort('p'); break;
            }

            tickets.display(tickets.gethead());
            Sleep(5000);
            system("cls");
            break;
        }

        case 5: {
            string name;
            cout << "Enter agent name:";
            cin >> name;
            allagents.addagent(name);
            Sleep(5000);
            system("cls");
            break;
        }

        case 6: {
            bool flag = false;
            while(!q3.isempty() && allagents.checkavailabilityforall()) {
                ticket temp = q3.peek();
                q3.dequeue();
                allagents.assignticket(temp);
                flag = true;
            }
            while (!q2.isempty() && allagents.checkavailabilityforall()) {
                ticket temp = q2.peek();
                q2.dequeue();
                allagents.assignticket(temp);
                flag = true;
            }
            while (!q1.isempty() && allagents.checkavailabilityforall()) {
                ticket temp = q1.peek();
                q1.dequeue();
                allagents.assignticket(temp);
                flag = true;
            }

            if (!flag) {
                if (q1.isempty() && q2.isempty() && q3.isempty())
                    cout << "No pending tickets" << endl;
                else
                    cout << "No available agents" << endl;
            }
            Sleep(5000);
            system("cls");
            break;
        }

        case 7: {
            allagents.displayallagents();
            if (!allagents.checkavailabilityforall())
                cout << "No available agents" << endl;
            Sleep(5000);
            system("cls");
            break;
        }

        case 8: {
            cout << "Display priority1:" << endl;
            q1.display();
            cout << "Display priority2:" << endl;
            q2.display();
            cout << "Display priority3:" << endl;
            q3.display();
            Sleep(5000);
            system("cls");
            break;
        }

        case 9: {
            pasttickets.display();
            Sleep(5000);
            system("cls");
            break;
        }

        case 10: {
            Node* newhead=tickets.opentickets();
            tickets.display(newhead);
        }

        case 11: {
            tickets.display(tickets.gethead());
            Sleep(5000);
            system("cls");
            break;
        }

        case 12: {
            allagents.displayallagents();
            if (allagents.allnotickets() == true) {
                cout << "No tickets to close for any agent" << endl;
                Sleep(5000);
                system("cls");
                break;
            }
 
            int choice, idx;
            cout << "Enter agent index where your ticket lies:";
            cin >> choice;
            if (choice < 1 || choice > allagents.curragents) {
                cout << "Incorrect agent index" << endl;
                Sleep(5000);
                system("cls");
                break;
            }

            cout << "Enter ticket idx to close:";
            cin >> idx;
            if (idx < 1 || idx > allagents.ptr[choice - 1]->assignedcount) {
                cout << "Incorrect ticket index" << endl;
                Sleep(5000);
                system("cls");
                break;
            }

            ticket temp=allagents.ptr[choice - 1]->closeticket(idx - 1);
            temp.displayticket();
            tickets.updatedatabase(temp);
            pasttickets.push(temp);
            Sleep(5000);
            system("cls");
            break;
        }

        case 13:{
            allagents.sortagents();
            Sleep(5000);
            system("cls");
            break;
        }

        case 14: {
            int sortchoice;
            int searchchoice;
            tickets.sortbyconfigsettings(sortchoice, searchchoice);
            cout << sortchoice << endl;
            cout << searchchoice << endl;
            Sleep(5000);
            system("cls");
            break;
        }

        case 15: {
            return 0;
        }

        default: {
            cout << "Invalid choice" << endl;
            Sleep(5000);
            system("cls");
            break;
        }
        }
    } while (1);
}
