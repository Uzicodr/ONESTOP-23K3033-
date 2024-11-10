#pragma once
#include<iostream>
#include "ticket.h"
using namespace std;

class Node {
private:
    ticket val;
    Node* next;

public:
    ticket getval() {
        return val;
    }

    Node* getptr() {
        return next;
    }

    void setval(ticket val) {
        this->val = val;
    }

    void setptr(Node* ptr) {
        next = ptr;
    }

    Node(ticket v, Node* ptr) {
        val = v;
        next = ptr;
    }

    Node(ticket temp) {
        val = temp;
        next = NULL;
    }

    Node() {
        next = NULL;
    }
};