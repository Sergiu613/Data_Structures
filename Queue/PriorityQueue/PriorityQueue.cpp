#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Element {
    std::string value;
    int priority;
};

class PriorityQueue {
private:
    std::vector<Element> queue;

public:
    bool isEmpty() const {
        return queue.empty();
    }

    void insert(const std::string& value, int priority) {
        Element new_elem = {value, priority};
        auto it = std::find_if(queue.begin(), queue.end(), [priority](const Element& e) {
            return e.priority < priority;
        });
        queue.insert(it, new_elem);
    }

    std::string dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue Underflow!" << std::endl;
            return "";
        }
        std::string val = queue.front().value;
        queue.erase(queue.begin());
        return val;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty" << std::endl;
            return;
        }
        std::cout << "Priority Queue: ";
        for (const auto& item : queue) {
            std::cout << "[" << item.value << ", P:" << item.priority << "] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert("Low", 1);
    pq.insert("High", 5);
    pq.insert("Medium", 3);
    pq.print();

    std::cout << "Dequeued: " << pq.dequeue() << std::endl;
    pq.print();
    return 0;
}
