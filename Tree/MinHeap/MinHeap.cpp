#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return (2 * i) + 1; }
    int rightChild(int i) const { return (2 * i) + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size() && heap[left] < heap[smallest]) smallest = left;
        if (right < size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    int size() const { return heap.size(); }
    bool isEmpty() const { return heap.empty(); }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(size() - 1);
    }

    int extractMin() {
        if (isEmpty()) throw std::underflow_error("Heap is empty");
        
        int rootVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!isEmpty()) heapifyDown(0);
        return rootVal;
    }

    int peek() const {
        if (isEmpty()) throw std::underflow_error("Heap is empty");
        return heap[0];
    }

    void print() const {
        std::cout << "Heap Array representation: ";
        for (int x : heap) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    MinHeap mh;
    mh.insert(15);
    mh.insert(10);
    mh.insert(20);
    mh.insert(5);
    
    mh.print();
    std::cout << "Extracted min: " << mh.extractMin() << "\n";
    mh.print();

    return 0;
}
