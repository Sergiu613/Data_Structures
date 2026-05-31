#include <iostream>

template <typename T, int Capacity>
class CircularQueue {
private:
    T data[Capacity];
    int front_idx;
    int rear_idx;
    int current_size;

public:
    CircularQueue() : front_idx(0), rear_idx(-1), current_size(0) {}

    bool isFull() const {
        return current_size == Capacity;
    }

    bool isEmpty() const {
        return current_size == 0;
    }

    bool enqueue(const T& value) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot enqueue " << value << std::endl;
            return false;
        }
        rear_idx = (rear_idx + 1) % Capacity;
        data[rear_idx] = value;
        current_size++;
        return true;
    }

    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Cannot dequeue" << std::endl;
            return T();
        }
        T value = data[front_idx];
        front_idx = (front_idx + 1) % Capacity;
        current_size--;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return T();
        }
        return data[front_idx];
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue (Front -> Rear): ";
        for (int i = 0; i < current_size; ++i) {
            int idx = (front_idx + i) % Capacity;
            std::cout << data[idx] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue<int, 4> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.print(); // 20 30 40
    return 0;
}
