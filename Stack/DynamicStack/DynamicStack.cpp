#include <iostream>

template <typename T>
class DynamicStack {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    Node* top_node;
    int stack_size;

public:
    DynamicStack() : top_node(nullptr), stack_size(0) {}

    ~DynamicStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top_node == nullptr;
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top_node;
        top_node = newNode;
        stack_size++;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop" << std::endl;
            return T();
        }
        Node* temp = top_node;
        T poppedValue = temp->value;
        top_node = top_node->next;
        delete temp;
        stack_size--;
        return poppedValue;
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return T();
        }
        return top_node->value;
    }

    int size() const {
        return stack_size;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Stack (Top -> Bottom):\n";
        Node* current = top_node;
        while (current != nullptr) {
            std::cout << "| " << current->value << " |\n";
            current = current->next;
        }
        std::cout << "-------\n";
    }
};

int main() {
    DynamicStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();

    std::cout << "Popped: " << stack.pop() << std::endl;
    stack.print();
    return 0;
}
