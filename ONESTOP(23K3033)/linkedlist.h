#include <iostream>
#include "Node.h"
#include "ticket.h"
#include<fstream>
using namespace std;

class ll {
private:
    Node* head;
    Node* tail;

public:
    Node* gethead() {
        return head;
    }
    ll() {
        head = NULL;
        tail = NULL;
    }

    void swap(ticket& t1, ticket& t2) {
        ticket temp = t1;
        t1 = t2;
        t2 = temp;
    }

    //bubble sort ased on priority
    void bubblesort_priority() {
        Node* i = head;
        while (i != NULL) {
            Node* j = head;
            while (j->getptr() != NULL) {
                if (j->getval().priority > j->getptr()->getval().priority) {
                    ticket temp = j->getval();
                    j->setval(j->getptr()->getval());
                    j->getptr()->setval(temp);
                }
                j = j->getptr();
            }
            i = i->getptr();
        }
    }

    // Selection Sort based on Priority
    void selectionsort_priority() {
        Node* i = head;
        while (i != NULL && i->getptr() != NULL) {
            Node* minidx = i;
            Node* j = i->getptr();
            while (j != NULL) {
                if (j->getval().priority < minidx->getval().priority) {
                    minidx = j;
                }
                j = j->getptr();
            }

            ticket temp = i->getval();
            i->setval(minidx->getval());
            minidx->setval(temp);

            i = i->getptr();
        }
    }

    // Insertion Sort based on Priority
    void insertionsort_priority() {
        if (head == NULL || head->getptr() == NULL) {
            return;
        }

        Node* sorted = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->getptr();

            if (sorted == NULL || sorted->getval().priority >= curr->getval().priority) {
                curr->setptr(sorted);
                sorted = curr;
            }
            else {
                Node* temp = sorted;
                while (temp->getptr() != NULL && temp->getptr()->getval().priority < curr->getval().priority) {
                    temp = temp->getptr();
                }
                curr->setptr(temp->getptr());
                temp->setptr(curr);
            }

            curr = next;
        }

        head = sorted;
    }

    // Bubble Sort based on Creation Time
    void bubblesort_creationtime() {
        Node* i = head;
        while (i != NULL) {
            Node* j = head;
            while (j->getptr() != NULL) {
                if (j->getval().creationtime > j->getptr()->getval().creationtime) {
                    ticket temp = j->getval();
                    j->setval(j->getptr()->getval());
                    j->getptr()->setval(temp);
                }
                j = j->getptr();
            }
            i = i->getptr();
        }
    }

    // Selection Sort based on Creation Time
    void selectionsort_creationtime() {
        Node* i = head;
        while (i != NULL && i->getptr() != NULL) {
            Node* minidx = i;
            Node* j = i->getptr();
            while (j != NULL) {
                if (j->getval().creationtime < minidx->getval().creationtime) {
                    minidx = j;
                }
                j = j->getptr();
            }

            ticket temp = i->getval();
            i->setval(minidx->getval());
            minidx->setval(temp);

            i = i->getptr();
        }
    }

    // Insertion Sort based on Creation Time
    void insertionsort_creationtime() {
        if (head == NULL || head->getptr() == NULL) {
            return;
        }

        Node* sorted = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->getptr();

            if (sorted == NULL || sorted->getval().creationtime >= curr->getval().creationtime) {
                curr->setptr(sorted);
                sorted = curr;
            }
            else {
                Node* temp = sorted;
                while (temp->getptr() != NULL && temp->getptr()->getval().creationtime < curr->getval().creationtime) {
                    temp = temp->getptr();
                }
                curr->setptr(temp->getptr());
                temp->setptr(curr);
            }

            curr = next;
        }

        head = sorted;
    }

    // Bubble Sort based on Close Time
    void bubblesort_closetime() {
        Node* i = head;
        while (i != NULL) {
            Node* j = head;
            while (j->getptr() != NULL) {
                if (j->getval().closetime > j->getptr()->getval().closetime) {
                    ticket temp = j->getval();
                    j->setval(j->getptr()->getval());
                    j->getptr()->setval(temp);
                }
                j = j->getptr();
            }
            i = i->getptr();
        }
    }

    // Selection Sort based on Close Time
    void selectionsort_closetime() {
        Node* i = head;
        while (i != NULL && i->getptr() != NULL) {
            Node* minidx = i;
            Node* j = i->getptr();
            while (j != NULL) {
                if (j->getval().closetime < minidx->getval().closetime) {
                    minidx = j;
                }
                j = j->getptr();
            }
            ticket temp = i->getval();
            i->setval(minidx->getval());
            minidx->setval(temp);
            i = i->getptr();
        }
    }

    // Insertion Sort based on Close Time
    void insertionsort_closetime() {
        if (head == NULL || head->getptr() == NULL) {
            return;
        }

        Node* sorted = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->getptr();

            if (sorted == NULL || sorted->getval().closetime >= curr->getval().closetime) {
                curr->setptr(sorted);
                sorted = curr;
            }
            else {
                Node* temp = sorted;
                while (temp->getptr() != NULL && temp->getptr()->getval().closetime < curr->getval().closetime) {
                    temp = temp->getptr();
                }
                curr->setptr(temp->getptr());
                temp->setptr(curr);
            }

            curr = next;
        }

        head = sorted;
    }


    Node* findmid(Node* node) {
        Node* slow = node;
        Node* fast = node->getptr();

        while (fast && fast->getptr()) {
            fast = fast->getptr()->getptr();
            slow = slow->getptr();
        }

        return slow;
    }

    Node* mergeit(Node* head1, Node* head2) { 
        Node* dummy = new Node(); 
        Node* newhead = dummy;  
        Node* temp1 = head1;
        Node* temp2 = head2;
        while (temp1 && temp2) {
            if(temp1->getval().priority < temp2->getval().priority) {
                dummy->setptr(temp1);
                dummy = temp1;
                temp1 = temp1->getptr();
            }
            else {
                dummy->setptr(temp2);
                dummy = temp2;
                temp2 = temp2->getptr();
            }
        }

        while (temp1) {
            dummy->setptr(temp1);
            dummy = temp1;
            temp1 = temp1->getptr();
        }
        while (temp2) {
            dummy->setptr(temp2);
            dummy = temp2;
            temp2 = temp2->getptr();
        }
        return newhead;
    }

    Node* mergesort(Node* head) {
        if (head == NULL || head->getptr() == NULL) {
            return head;
        }

        Node* mid = findmid(head);
        Node* right = mid->getptr();
        mid->setptr(NULL);

        Node* left_sorted = mergesort(head);  
        Node* right_sorted = mergesort(right);
        return mergeit(left_sorted, right_sorted);
    }

    void swap(Node* a, Node* b) {
        ticket temp = a->getval();  // Swap the tickets in the nodes
        a->setval(b->getval());
        b->setval(temp);
    }

    Node* findmid(Node* low, Node* high,char c) {
        ticket pivot = low->getval();  // Pivot is the ticket at the low node
        Node* i = low;

        for (Node* j = low->getptr(); j != high->getptr(); j = j->getptr()) {
            if (c == 'p') {
                if (j->getval().priority < pivot.priority) {  // Compare based on priority
                    i = i->getptr();
                    swap(i, j);  // Swap nodes if j's priority is less than the pivot
                }
            }

            if (c == 'i') {
                if (j->getval().id < pivot.id) {  // Compare based on priority
                    i = i->getptr();
                    swap(i, j);  // Swap nodes if j's priority is less than the pivot
                }
            }

            if (c == 's') {
                if (j->getval().creationtime < pivot.creationtime) {  // Compare based on priority
                    i = i->getptr();
                    swap(i, j);  // Swap nodes if j's priority is less than the pivot
                }
            }

            if (c == 'e') {
                if (j->getval().closetime < pivot.closetime) {  // Compare based on priority
                    i = i->getptr();
                    swap(i, j);  // Swap nodes if j's priority is less than the pivot
                }
            }

            }
        swap(i, low);  // Swap the pivot node with the i-th node
        return i;  // Return the partition point
    }

    void merge() {
       mergesort(head);
    }

    void qs(Node* low, Node* high,char c) {
        if (low != high && low != NULL && high != NULL && high->getptr() != low) {
            Node* partition = findmid(low, high,c);

            // Find the node just before the partition
            Node* onelessthanpartition = low;
            while (onelessthanpartition != NULL && onelessthanpartition->getptr() != partition) {
                onelessthanpartition = onelessthanpartition->getptr();
            }

            qs(low, onelessthanpartition,c);     // Recursively sort the left part
            qs(partition->getptr(), high,c);     // Recursively sort the right part
        }
    }

    void quicksort(char c) {
        if (head == NULL || head->getptr() == NULL) {
            return;
        }

        Node* low = head;
        Node* high = head;

        // Move high to the last node
        while (high->getptr() != NULL) {
            high = high->getptr();
        }

        qs(low, high,c);  // Start quicksort from low to high
    }

    Node* opentickets() {
        if (head == NULL) {
            return NULL;
        }

        Node* temp = head;
        Node* newhead = NULL;  // New head for the list of open tickets
        Node* lastOpenTicket = NULL;  // Tracks the last open ticket node

        while (temp) {
            if (temp->getval().status == true) {
                if (newhead == NULL) {
                    // First open ticket found, set newhead
                    newhead = temp;
                    lastOpenTicket = newhead;
                }
                else {
                    // Link the current open ticket to the last open ticket
                    lastOpenTicket->setptr(temp);
                    lastOpenTicket = lastOpenTicket->getptr();  // Move to the next node
                }
            }
            temp = temp->getptr();  // Move to the next node in the original list
        }

        // Ensure the last node in the new list points to NULL
        if (lastOpenTicket != NULL) {
            lastOpenTicket->setptr(NULL);
        }

        return newhead;
    }


    void display(Node* node) {
        Node* mover = node;
        while (mover) {
            mover->getval().displayticket();
            mover = mover->getptr();
        }
        cout << endl;
    }

    int lengthofll() {
        Node* mover = head;
        int count = 0;
        while (mover) {
            count++;
            mover = mover->getptr();
        }
        return count;
    }

    ticket searchid(int id) {
        if (head == NULL) {
            // List is empty
            cout << "No tickets" << endl;
            return {};
        }

        Node* temp = head;
        while (temp) {
            if (temp->getval().ticketid == id) {
                return temp->getval();
            }
            temp = temp->getptr();
        }
        return {};
    }

    void updatedatabase(ticket updated) {
        Node* temp=head;
        while (temp!=NULL) {
            if (temp->getval().ticketid == updated.ticketid) {
                temp->setval(updated);
                return;
            }
            temp = temp->getptr();
        }

        if (temp == NULL) {
            cout << "No database to update" << endl;
            return;
        }
    }

    int searchidx(int id) {
        if (head == NULL) {
            // List is empty
            cout << "No tickets" << endl;
            return {};
        }

        Node* temp = head;
        int i = 0;
        while (temp) {
            if (temp->getval().ticketid == id) {
                return i;
            }
            temp = temp->getptr();
            i++;
        }
        return -1;
    }

    void deleteathead() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = temp->getptr();
        delete temp;
    }

    void deleteattail() {
        if (head == NULL || head->getptr() == NULL)
            return;
        Node* temp = head;
        while (temp->getptr()->getptr()) {
            temp = temp->getptr();
        }
        delete temp->getptr();
        temp->setptr(NULL);
        tail = temp;
    }

    void deleteatkth(int id) {
        if (head->getval().ticketid == id) {
            deleteathead();
            return;
        }
        Node* temp = head;
        Node* deleted = temp;
        while (temp) {
            if (id == temp->getptr()->getval().ticketid) {
                deleted = temp->getptr();
                temp->setptr(temp->getptr()->getptr());
                delete deleted;
                return;
            }
            temp = temp->getptr();
        }
    }

    void insertattail(ticket val) {
        Node* temp = new Node(val, NULL);
        if (tail != NULL) {
            tail->setptr(temp);
        }
        tail = temp;
        if (head == NULL) {
            head = tail;
        }
    }

    ticket binarysearch(int ticketid) {
        quicksort('p');
        Node* low = head;
        Node* high = NULL;

        do {
            Node* mid = findmid(low, high,'p');

            if (mid->getval().ticketid == ticketid) {
                return mid->getval();
            }
            else if (mid->getval().ticketid < ticketid) {
                low = mid->getptr();
            }
            else {
                high = mid;
            }
        } while (high == NULL || high->getptr() != low);

        cout << "Ticket not found!" << endl;
        return {};
    }


    int sortbyconfigsettings(int& sortchoice, int &searchchoice) {
        ifstream file("configfile.txt");
        if (!file) {
            cerr << "Error Opening the file" << endl;
            return -1;
        }

        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
            if (count == 8) {
                sortchoice = line[line.length() - 1] - '0';
            }
            if (count == 12) {
                searchchoice = line[line.length() - 1] - '0';
            }
        }
        file.close();
        return 0;
    }
};
