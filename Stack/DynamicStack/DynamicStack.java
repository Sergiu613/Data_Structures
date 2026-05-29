public class DynamicStack {
    private static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    private Node top;
    private int size;

    public DynamicStack() {
        this.top = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void push(int value) {
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;
        size++;
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop");
            return -1;
        }
        int poppedValue = top.value;
        top = top.next;
        size--;
        return poppedValue;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return -1;
        }
        return top.value;
    }

    public int size() {
        return size;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.println("Stack (Top -> Bottom):");
        Node current = top;
        while (current != null) {
            System.out.println("| " + current.value + " |");
            current = current.next;
        }
        System.out.println("-------");
    }

    public static void main(String[] args) {
        DynamicStack stack = new DynamicStack();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.print();

        System.out.println("Popped: " + stack.pop());
        System.out.println("Top element: " + stack.peek());
        stack.print();
    }
}
