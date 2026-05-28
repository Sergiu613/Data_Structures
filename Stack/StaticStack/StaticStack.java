public class StaticStack {
    private int[] stack;
    private int top;
    private int capacity;

    public StaticStack(int capacity) {
        this.capacity = capacity;
        this.stack = new int[capacity];
        this.top = -1;
    }

    public boolean isFull() {
        return top == capacity - 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + value);
            return false;
        }
        stack[++top] = value;
        return true;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop");
            return -1;
        }
        return stack[top--];
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return -1;
        }
        return stack[top];
    }

    public int size() {
        return top + 1;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.println("Stack (Top -> Bottom):");
        for (int i = top; i >= 0; i--) {
            System.out.println("| " + stack[i] + " |");
        }
        System.out.println("-------");
    }

    public static void main(String[] args) {
        StaticStack stack = new StaticStack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.print();

        System.out.println("Popped: " + stack.pop());
        System.out.println("Top element: " + stack.peek());
        stack.print();
    }
}
