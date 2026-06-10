class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root_value):
        self.root = Node(root_value)

    def traverse_in_order(self, node):
        if node:
            self.traverse_in_order(node.left)
            print(node.value, end=" ")
            self.traverse_in_order(node.right)

    def traverse_pre_order(self, node):
        if node:
            print(node.value, end=" ")
            self.traverse_pre_order(node.left)
            self.traverse_pre_order(node.right)

    def traverse_post_order(self, node):
        if node:
            self.traverse_post_order(node.left)
            self.traverse_post_order(node.right)
            print(node.value, end=" ")

if __name__ == "__main__":
    #        1
    #       / \
    #      2   3
    tree = BinaryTree(1)
    tree.root.left = Node(2)
    tree.root.right = Node(3)

    print("In-Order traversal:")
    tree.traverse_in_order(tree.root)  # Output: 2 1 3
    print("\nPre-Order traversal:")
    tree.traverse_pre_order(tree.root)  # Output: 1 2 3
    print("\nPost-Order traversal:")
    tree.traverse_post_order(tree.root)  # Output: 2 3 1
    print()
