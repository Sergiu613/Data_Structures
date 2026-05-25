#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }

    void insert(int value, int position) {
        if (position == 0) {
            prepend(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
            if (current == head) return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFirst() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        Node* temp = head;
        current->next = head->next;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }
        prev->next = head;
        delete current;
    }

    void deleteAt(int position) {
        if (!head) return;
        if (position == 0) {
            deleteFirst();
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        for (int i = 0; i < position; ++i) {
            prev = current;
            current = current->next;
            if (current == head) return;
        }
        prev->next = current->next;
        delete current;
    }

    int search(int value) {
        if (!head) return -1;
        Node* current = head;
        int position = 0;
        do {
            if (current->value == value) return position;
            current = current->next;
            position++;
        } while (current != head);
        return -1;
    }

    void print() {
        if (!head) {
            std::cout << "Empty List" << std::endl;
            return;
        }
        Node* current = head;
        do {
            std::cout << current->value << " -> ";
            current = current->next;
        } while (current != head);
        std::cout << "(head)" << std::endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.append(10);
    cll.append(20);
    cll.prepend(5);
    cll.insert(15, 2);
    cll.print(); // 5 -> 10 -> 15 -> 20 -> (head)
    return 0;
}
