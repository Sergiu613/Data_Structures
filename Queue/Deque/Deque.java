public class Deque {
    private int[] arr;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public Deque(int capacity) {
        this.capacity = capacity;
        this.arr = new int[capacity];
        this.front = -1;
        this.rear = -1;
        this.size = 0;
    }

    public boolean isFull() { return size == capacity; }
    public boolean isEmpty() { return size == 0; }

    public boolean insertFront(int value) {
        if (isFull()) {
            System.out.println("Deque Overflow! Cannot insert " + value + " at Front");
            return false;
        }
        if (front == -1) {
            front = 0; rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    public boolean insertRear(int value) {
        if (isFull()) {
            System.out.println("Deque Overflow! Cannot insert " + value + " at Rear");
            return false;
        }
        if (front == -1) {
            front = 0; rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    public int deleteFront() {
        if (isEmpty()) {
            System.out.println("Deque Underflow! Cannot delete from Front");
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1; rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }

    public int deleteRear() {
        if (isEmpty()) {
            System.out.println("Deque Underflow! Cannot delete from Rear");
            return -1;
        }
        int value = arr[rear];
        if (front == rear) {
            front = -1; rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return value;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Deque is empty");
            return;
        }
        System.out.print("Deque (Front -> Rear): ");
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            System.out.print(arr[idx] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Deque dq = new Deque(5);
        dq.insertRear(10);
        dq.insertFront(5);
        dq.insertRear(15);
        dq.print(); // 5 10 15
        
        dq.deleteRear();
        dq.print(); // 5 10
    }
}
