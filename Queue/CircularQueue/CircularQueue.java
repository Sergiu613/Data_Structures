public class CircularQueue {
    private int[] data;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        this.data = new int[capacity];
        this.front = 0;
        this.rear = -1;
        this.size = 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue Overflow! Cannot enqueue " + value);
            return false;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue Underflow! Cannot dequeue");
            return -1;
        }
        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }
        return data[front];
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue (Front -> Rear): ");
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            System.out.print(data[idx] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        CircularQueue q = new CircularQueue(4);
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.dequeue();
        q.enqueue(40);
        q.print(); // 20 30 40
    }
}
