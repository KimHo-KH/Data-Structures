#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// LinkedList class declaration
class LinkedList {
public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Function to add a new node to the end of the list
    void append(int value);

    // Function to display the linked list
    void display();

private:
    Node* head; // Pointer to the head of the linked list
};

#endif
