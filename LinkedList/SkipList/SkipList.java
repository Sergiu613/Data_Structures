import java.util.Arrays;
import java.util.Random;

public class SkipList {
    private static class SkipNode {
        int value;
        SkipNode[] next;

        SkipNode(int value, int level) {
            this.value = value;
            this.next = new SkipNode[level + 1];
        }
    }

    private final int MAX_LEVEL = 4;
    private final float P = 0.5f;
    private int level = 0;
    private final SkipNode header;
    private final Random rand = new Random();

    public SkipList() {
        header = new SkipNode(Integer.MIN_VALUE, MAX_LEVEL);
    }

    private int randomLevel() {
        int lvl = 0;
        while (rand.nextFloat() < P && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

    public void insert(int value) {
        SkipNode[] update = new SkipNode[MAX_LEVEL + 1];
        SkipNode current = header;

        for (int i = level; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].value < value) {
                current = current.next[i];
            }
            update[i] = current;
        }
        current = current.next[0];

        if (current == null || current.value != value) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            SkipNode newNode = new SkipNode(value, rlevel);
            for (int i = 0; i <= rlevel; i++) {
                newNode.next[i] = update[i].next[i];
                update[i].next[i] = newNode;
            }
        }
    }

    public boolean search(int value) {
        SkipNode current = header;
        for (int i = level; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].value < value) {
                current = current.next[i];
            }
        }
        current = current.next[0];
        return current != null && current.value == value;
    }

    public void delete(int value) {
        SkipNode[] update = new SkipNode[MAX_LEVEL + 1];
        SkipNode current = header;

        for (int i = level; i >= 0; i--) {
            while (current.next[i] != null && current.next[i].value < value) {
                current = current.next[i];
            }
            update[i] = current;
        }
        current = current.next[0];

        if (current != null && current.value == value) {
            for (int i = 0; i <= level; i++) {
                if (update[i].next[i] != current) break;
                update[i].next[i] = current.next[i];
            }
            while (level > 0 && header.next[level] == null) {
                level--;
            }
        }
    }

    public void print() {
        System.out.println("\n--- Skip List Levels ---");
        for (int i = level; i >= 0; i--) {
            SkipNode node = header.next[i];
            System.out.print("Level " + i + ": ");
            while (node != null) {
                System.out.print(node.value + " -> ");
                node = node.next[i];
            }
            System.out.println("null");
        }
    }

    public static void main(String[] args) {
        SkipList sl = new SkipList();
        sl.insert(4);
        sl.insert(8);
        sl.insert(15);
        sl.print();
        System.out.println("Search 8: " + sl.search(8));
        sl.delete(8);
        sl.print();
    }
}
