#pragma once
#include<iostream>
#include "Node.h"
#include "ticket.h"
using namespace std;

class Pendingqueue {
private:
    Node* front;
    Node* rear;

public:
    Pendingqueue() {
        front = NULL;
        rear = NULL;
    }

    // Check if the queue is empty
    bool isempty() {
        return (front == NULL);
    }

    // Enqueue operation
    void enqueue(ticket value) {
        Node* newnode = new Node(value,NULL);

        if (isempty()) {
            front = newnode;
            rear = newnode;
            rear->setptr(front);  // Circular link
        }

        else {
            rear->setptr(newnode);
            rear = newnode;
            rear->setptr(front);  // Maintain circular link
        }
    }

    // Dequeue operation
    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // If there's only one element
        if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->getptr();
            rear->setptr(front);  // Maintain circular link
            delete temp;
        }
    }

    // Peek the front element
    ticket peek() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            // Return a default ticket if empty
            return ticket();
        }
        return front->getval();
    }

    // Display the queue
    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* mover = front;
        do {
            mover->getval().displayticket();
            mover = mover->getptr();
        } while (mover != front);  // Stop when we come back to the front,kyunke circular hai

        cout << endl;
    }

    // Destructor to clean up memory
    ~Pendingqueue() {
        while (!isempty()) {
            dequeue();
        }
    }
};
