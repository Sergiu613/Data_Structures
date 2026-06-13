import java.util.ArrayList;
import java.util.Collections;

public class MinHeap {
    private ArrayList<Integer> heap;

    public MinHeap() {
        this.heap = new ArrayList<>();
    }

    public int size() { return heap.size(); }
    public boolean isEmpty() { return heap.isEmpty(); }

    private int parent(int i) { return (i - 1) / 2; }
    private int leftChild(int i) { return (2 * i) + 1; }
    private int rightChild(int i) { return (2 * i) + 2; }

    public void insert(int value) {
        heap.add(value);
        heapifyUp(size() - 1);
    }

    private void heapifyUp(int i) {
        while (i > 0 && heap.get(i) < heap.get(parent(i))) {
            Collections.swap(heap, i, parent(i));
            i = parent(i);
        }
    }

    public int extractMin() {
        if (isEmpty()) throw new IllegalStateException("Heap Underflow");
        if (size() == 1) return heap.remove(0);

        int minVal = heap.get(0);
        heap.set(0, heap.remove(size() - 1));
        heapifyDown(0);
        return minVal;
    }

    public int peek() {
        if (isEmpty()) throw new IllegalStateException("Heap is empty");
        return heap.get(0);
    }

    public void print() {
        System.out.println("Min Heap Array: " + heap);
    }

    public static void main(String[] args) {
        MinHeap mh = new MinHeap();
        mh.insert(15);
        mh.insert(10);
        mh.insert(20);
        mh.insert(5);
        mh.insert(8);

        mh.print();
        System.out.println("Extracted minimum: " + mh.extractMin());
        mh.print();
    }
}
