#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void insert(int value, int position) {
        if (position == 0) {
            prepend(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            if (!current) return;
            current = current->next;
        }
        if (!current) return;

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->prev->next = nullptr;
        delete current;
    }

    void deleteAt(int position) {
        if (!head) return;
        if (position == 0) {
            deleteFirst();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position; ++i) {
            if (!current) return;
            current = current->next;
        }
        if (!current) return;

        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        delete current;
    }

    int search(int value) {
        Node* current = head;
        int position = 0;
        while (current) {
            if (current->value == value) return position;
            current = current->next;
            position++;
        }
        return -1;
    }

    void print() {
        Node* current = head;
        if (!current) {
            std::cout << "Empty List" << std::endl;
            return;
        }
        while (current) {
            std::cout << current->value;
            if (current->next) std::cout << " <-> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(20);
    dll.prepend(5);
    dll.insert(15, 2);
    dll.print(); // 5 <-> 10 <-> 15 <-> 20
    return 0;
}
