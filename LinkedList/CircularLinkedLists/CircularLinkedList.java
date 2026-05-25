public class CircularLinkedList {
    private static class Node {
        int value;
        Node next;
        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    private Node head = null;

    public void prepend(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            newNode.next = newNode;
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != head) {
            current = current.next;
        }
        newNode.next = head;
        current.next = newNode;
        head = newNode;
    }

    public void append(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            newNode.next = newNode;
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != head) {
            current = current.next;
        }
        current.next = newNode;
        newNode.next = head;
    }

    public void insert(int value, int position) {
        if (position == 0) {
            prepend(value);
            return;
        }
        Node newNode = new Node(value);
        Node current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current.next;
            if (current == head) return;
        }
        newNode.next = current.next;
        current.next = newNode;
    }

    public void deleteFirst() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
            return;
        }
        Node current = head;
        while (current.next != head) {
            current = current.next;
        }
        current.next = head.next;
        head = head.next;
    }

    public void deleteLast() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
            return;
        }
        Node current = head;
        Node prev = null;
        while (current.next != head) {
            prev = current;
            current = current.next;
        }
        prev.next = head;
    }

    public void delete(int position) {
        if (head == null) return;
        if (position == 0) {
            deleteFirst();
            return;
        }
        Node current = head;
        Node prev = null;
        for (int i = 0; i < position; i++) {
            prev = current;
            current = current.next;
            if (current == head) return;
        }
        prev.next = current.next;
    }

    public int search(int value) {
        if (head == null) return -1;
        Node current = head;
        int position = 0;
        do {
            if (current.value == value) return position;
            current = current.next;
            position++;
        } while (current != head);
        return -1;
    }

    public void print() {
        if (head == null) {
            System.out.println("Empty List");
            return;
        }
        Node current = head;
        do {
            System.out.print(current.value + " -> ");
            current = current.next;
        } while (current != head);
        System.out.println("(head)");
    }

    public static void main(String[] args) {
        CircularLinkedList cll = new CircularLinkedList();
        cll.append(10);
        cll.append(20);
        cll.prepend(5);
        cll.insert(15, 2);
        cll.print(); // 5 -> 10 -> 15 -> 20 -> (head)
    }
}
