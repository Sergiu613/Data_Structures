#include <iostream>

// Class representing a single node in the list
class Node {
public:
    int value;
    Node* next;

    // Constructor to initialize the node
    Node(int val) : value(val), next(nullptr) {}
};

// Class representing the Linked List
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor: automatically cleans up memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert a value at the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a value at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a value at a specific position
    void insertAt(int value, int position) {
        if (position <= 0) {
            prepend(value);
            return;
        }

        Node* temp = head;
        int i = 0;
        // Traverse to the node before the target position
        while (temp != nullptr && i < position - 1) {
            temp = temp->next;
            i++;
        }

        // If position is beyond list length, append to the end
        if (temp == nullptr) {
            append(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete the first node
    void deleteFirst() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last node
    void deleteLast() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a node at a specific position
    void removeAt(int position) {
        if (head == nullptr) return;

        if (position == 0) {
            deleteFirst();
            return;
        }

        Node* temp = head;
        for (int i = 0; temp->next != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Search for a value and return its position (index)
    int search(int value) {
        Node* temp = head;
        int pos = 0;
        while (temp != nullptr) {
            if (temp->value == value) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; // Value not found
    }

    // Print the entire list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};
