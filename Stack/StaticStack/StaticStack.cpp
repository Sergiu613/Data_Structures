#include <iostream>

template <typename T, int Capacity>
class StaticStack {
private:
    T data[Capacity];
    int top_idx;

public:
    StaticStack() : top_idx(-1) {}

    bool isFull() const {
        return top_idx == Capacity - 1;
    }

    bool isEmpty() const {
        return top_idx == -1;
    }

    bool push(const T& value) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push " << value << std::endl;
            return false;
        }
        data[++top_idx] = value;
        return true;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop" << std::endl;
            return T();
        }
        return data[top_idx--];
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return T();
        }
        return data[top_idx];
    }

    int size() const {
        return top_idx + 1;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Stack (Top -> Bottom):\n";
        for (int i = top_idx; i >= 0; --i) {
            std::cout << "| " << data[i] << " |\n";
        }
        std::cout << "-------\n";
    }
};

int main() {
    StaticStack<int, 5> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();

    std::cout << "Popped: " << stack.pop() << std::endl;
    stack.print();
    return 0;
}
