import java.util.ArrayList;

public class PriorityQueue {
    private static class Element {
        String value;
        int priority;

        Element(String value, int priority) {
            this.value = value;
            this.priority = priority;
        }
    }

    private ArrayList<Element> queue = new ArrayList<>();

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public void insert(String value, int priority) {
        Element newElement = new Element(value, priority);
        int i = 0;
        while (i < queue.size() && queue.get(i).priority >= priority) {
            i++;
        }
        queue.add(i, newElement);
    }

    public String dequeue() {
        if (isEmpty()) {
            System.out.println("Priority Queue Underflow!");
            return null;
        }
        return queue.remove(0).value;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Priority Queue is empty");
            return;
        }
        System.out.print("Priority Queue: ");
        for (Element e : queue) {
            System.out.print("[" + e.value + ", P:" + e.priority + "] ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue();
        pq.insert("Low", 1);
        pq.insert("High", 5);
        pq.insert("Medium", 3);
        pq.print();

        System.out.println("Dequeued: " + pq.dequeue());
        pq.print();
    }
}
