import java.util.ArrayList;
import java.util.List;

public class GeneralTree {
    private static class TreeNode {
        String value;
        List<TreeNode> children;

        TreeNode(String value) {
            this.value = value;
            this.children = new ArrayList<>();
        }
    }

    private TreeNode root;

    public GeneralTree(String rootValue) {
        this.root = new TreeNode(rootValue);
    }

    private TreeNode search(TreeNode current, String value) {
        if (current == null) return null;
        if (current.value.equals(value)) return current;

        for (TreeNode child : current.children) {
            TreeNode found = search(child, value);
            if (found != null) return found;
        }
        return null;
    }

    public void addChild(String parentValue, String childValue) {
        TreeNode parent = search(root, parentValue);
        if (parent != null) {
            parent.children.add(new TreeNode(childValue));
        } else {
            System.out.println("Parent '" + parentValue + "' not found!");
        }
    }

    public void print(TreeNode node, int level) {
        if (node == null) return;
        
        for (int i = 0; i < level; i++) System.out.print("  ");
        System.out.println("|-- " + node.value);
        
        for (TreeNode child : node.children) {
            print(child, level + 1);
        }
    }

    public void display() {
        print(root, 0);
    }

    public static void main(String[] args) {
        GeneralTree tree = new GeneralTree("Root");
        tree.addChild("Root", "Folder_A");
        tree.addChild("Root", "Folder_B");
        tree.addChild("Folder_A", "File_A1");
        tree.addChild("Folder_A", "File_A2");
        tree.addChild("Folder_B", "File_B1");

        tree.display();
    }
}
