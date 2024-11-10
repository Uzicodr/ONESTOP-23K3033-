#pragma once
#include<iostream>
#include "ticket.h"
#include "Node.h"
using namespace std;

class logged_stack {
    Node* head;

public:
    logged_stack() {
        head = NULL;
    }

    Node* top() {
        return head;
    }

    void push(ticket temp) {
        Node* newnode = new Node(temp);
        if (head != NULL) {
            newnode->setptr(head);
        }
        head = newnode;
    }

    bool isempty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void pop() {
        if (isempty()) {
            cout << "No ticket in stack!!" << endl;
            return;
        }

        Node* temp = head;
        head = head->getptr();
        delete temp;
    }

    void display() {
        Node* mover = head;
        while (mover) {
            mover->getval().displayticket();
            mover = mover->getptr();
        }
        cout << endl;
    }
};

