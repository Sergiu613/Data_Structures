public class BinarySearchTree {
    private static class Node {
        int value;
        Node left, right;
        Node(int value) {
            this.value = value;
            this.left = this.right = null;
        }
    }

    private Node root = null;

    public void insert(int value) {
        root = insertRecursive(root, value);
    }

    private Node insertRecursive(Node current, int value) {
        if (current == null) return new Node(value);
        if (value < current.value) current.left = insertRecursive(current.left, value);
        else if (value > current.value) current.right = insertRecursive(current.right, value);
        return current;
    }

    public int findMin() {
        if (root == null) throw new IllegalStateException("Tree is empty");
        return findMinNode(root).value;
    }

    private Node findMinNode(Node node) {
        Node current = node;
        while (current.left != null) current = current.left;
        return current;
    }

    public void delete(int value) {
        root = deleteRecursive(root, value);
    }

    private Node deleteRecursive(Node current, int value) {
        if (current == null) return null;

        if (value < current.value) {
            current.left = deleteRecursive(current.left, value);
        } else if (value > current.value) {
            current.right = deleteRecursive(current.right, value);
        } else {
            // Case 1 & 2
            if (current.left == null) return current.right;
            if (current.right == null) return current.left;

            // Case 3
            Node successor = findMinNode(current.right);
            current.value = successor.value;
            current.right = deleteRecursive(current.right, successor.value);
        }
        return current;
    }

    public int getHeight() {
        return getHeightRecursive(root);
    }

    private int getHeightRecursive(Node node) {
        if (node == null) return -1;
        return Math.max(getHeightRecursive(node.left), getHeightRecursive(node.right)) + 1;
    }

    public void printInOrder() {
        inOrder(root);
        System.out.println();
    }

    private void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.value + " ");
            inOrder(node.right);
        }
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] data = {50, 30, 70, 20, 40, 60, 80};
        for (int x : data) bst.insert(x);

        System.out.print("Tree In-Order: ");
        bst.printInOrder();
        System.out.println("Tree Height: " + bst.getHeight());

        System.out.println("Deleting node 20 (Leaf)...");
        bst.delete(20);
        bst.printInOrder();
    }
}
