#include <iostream>

template <typename T, int Capacity>
class LinearQueue {
private:
    T data[Capacity];
    int front_idx;
    int rear_idx;
    int current_size;

public:
    LinearQueue() : front_idx(0), rear_idx(-1), current_size(0) {}

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
        data[++rear_idx] = value;
        current_size++;
        return true;
    }

    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Cannot dequeue" << std::endl;
            return T();
        }
        current_size--;
        return data[front_idx++];
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return T();
        }
        return data[front_idx];
    }

    int size() const {
        return current_size;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue (Front -> Rear): ";
        for (int i = front_idx; i <= rear_idx; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LinearQueue<int, 5> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    q.print();
    return 0;
}
