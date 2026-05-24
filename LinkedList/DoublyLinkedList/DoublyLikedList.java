public class DoublyLinkedList {
    private static class Node {
        int value;
        Node next;
        Node prev;
        Node(int value) {
            this.value = value;
            this.next = null;
            this.prev = null;
        }
    }

    private Node head = null;

    public void prepend(int value) {
        Node newNode = new Node(value);
        if (head != null) {
            head.prev = newNode;
            newNode.next = head;
        }
        head = newNode;
    }

    public void append(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
        newNode.prev = current;
    }

    public void insert(int value, int position) {
        if (position == 0) {
            prepend(value);
            return;
        }
        Node newNode = new Node(value);
        Node current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == null) return;
            current = current.next;
        }
        if (current == null) return;

        newNode.next = current.next;
        newNode.prev = current;
        if (current.next != null) {
            current.next.prev = newNode;
        }
        current.next = newNode;
    }

    public void deleteFirst() {
        if (head == null) return;
        head = head.next;
        if (head != null) head.prev = null;
    }

    public void deleteLast() {
        if (head == null) return;
        if (head.next == null) {
            head = null;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.prev.next = null;
    }

    public void delete(int position) {
        if (head == null) return;
        if (position == 0) {
            deleteFirst();
            return;
        }
        Node current = head;
        for (int i = 0; i < position; i++) {
            if (current == null) return;
            current = current.next;
        }
        if (current == null) return;

        if (current.prev != null) current.prev.next = current.next;
        if (current.next != null) current.next.prev = current.prev;
    }

    public int search(int value) {
        Node current = head;
        int position = 0;
        while (current != null) {
            if (current.value == value) return position;
            current = current.next;
            position++;
        }
        return -1;
    }

    public void print() {
        Node current = head;
        if (current == null) {
            System.out.println("Empty List");
            return;
        }
        while (current != null) {
            System.out.print(current.value);
            if (current.next != null) System.out.print(" <-> ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        dll.append(10);
        dll.append(20);
        dll.prepend(5);
        dll.insert(15, 2);
        dll.print(); // 5 <-> 10 <-> 15 <-> 20
    }
}
