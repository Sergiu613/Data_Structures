#include <iostream>

template <typename T, int Capacity>
class Deque {
private:
    T arr[Capacity];
    int front;
    int rear;
    int current_size;

public:
    Deque() : front(-1), rear(-1), current_size(0) {}

    bool isFull() const { return current_size == Capacity; }
    bool isEmpty() const { return current_size == 0; }
    int size() const { return current_size; }

    bool insertFront(const T& value) {
        if (isFull()) {
            std::cout << "Deque Overflow! Front insert failed for " << value << std::endl;
            return false;
        }
        if (front == -1) {
            front = 0; rear = 0;
        } else {
            front = (front - 1 + Capacity) % Capacity;
        }
        arr[front] = value;
        current_size++;
        return true;
    }

    bool insertRear(const T& value) {
        if (isFull()) {
            std::cout << "Deque Overflow! Rear insert failed for " << value << std::endl;
            return false;
        }
        if (front == -1) {
            front = 0; rear = 0;
        } else {
            rear = (rear + 1) % Capacity;
        }
        arr[rear] = value;
        current_size++;
        return true;
    }

    T deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque Underflow! Front delete failed" << std::endl;
            return T();
        }
        T value = arr[front];
        if (front == rear) {
            front = -1; rear = -1;
        } else {
            front = (front + 1) % Capacity;
        }
        current_size--;
        return value;
    }

    T deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque Underflow! Rear delete failed" << std::endl;
            return T();
        }
        T value = arr[rear];
        if (front == rear) {
            front = -1; rear = -1;
        } else {
            rear = (rear - 1 + Capacity) % Capacity;
        }
        current_size--;
        return value;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        std::cout << "Deque (Front -> Rear): ";
        for (int i = 0; i < current_size; ++i) {
            int idx = (front + i) % Capacity;
            std::cout << arr[idx] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque<int, 5> dq;
    dq.insertRear(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.print(); // 20 10 30
    
    dq.deleteFront();
    dq.print(); // 10 30
    return 0;
}
