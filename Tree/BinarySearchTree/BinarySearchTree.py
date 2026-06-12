class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        self.root = self._insert_recursive(self.root, value)

    def _insert_recursive(self, current, value):
        if current is None:
            return Node(value)
        if value < current.value:
            current.left = self._insert_recursive(current.left, value)
        elif value > current.value:
            current.right = self._insert_recursive(current.right, value)
        return current

    def search(self, value):
        return self._search_recursive(self.root, value)

    def _search_recursive(self, current, value):
        if current is None:
            return False
        if current.value == value:
            return True
        if value < current.value:
            return self._search_recursive(current.left, value)
        return self._search_recursive(current.right, value)

    def find_min(self, node=None):
        current = node if node else self.root
        if current is None:
            return None
        while current.left is not None:
            current = current.left
        return current.value

    def find_max(self, node=None):
        current = node if node else self.root
        if current is None:
            return None
        while current.right is not None:
            current = current.right
        return current.value

    def delete(self, value):
        self.root = self._delete_recursive(self.root, value)

    def _delete_recursive(self, current, value):
        if current is None:
            return current

        if value < current.value:
            current.left = self._delete_recursive(current.left, value)
        elif value > current.value:
            current.right = self._delete_recursive(current.right, value)
        else:
            # Case 1 & 2: Node has one child or no children
            if current.left is None:
                return current.right
            elif current.right is None:
                return current.left

            # Case 3: Node has two children
            # Find the in-order successor (smallest in the right subtree)
            successor_value = self.find_min(current.right)
            current.value = successor_value
            # Delete the duplicate successor node from the right branch
            current.right = self._delete_recursive(current.right, successor_value)

        return current

    def get_height(self, node=None):
        if node is None:
            return -1  # Height of empty tree is -1
        left_height = self.get_height(node.left)
        right_height = self.get_height(node.right)
        return max(left_height, right_height) + 1

    def traverse_in_order(self, node):
        if node:
            self.traverse_in_order(node.left)
            print(node.value, end=" ")
            self.traverse_in_order(node.right)

if __name__ == "__main__":
    bst = BinarySearchTree()
    nodes = [50, 30, 70, 20, 40, 60, 80]
    for val in nodes:
        bst.insert(val)

    print("Initial In-Order traversal (Sorted):")
    bst.traverse_in_order(bst.root)  # 20 30 40 50 60 70 80
    print(f"\nMinimum: {bst.find_min()} | Maximum: {bst.find_max()}")
    print(f"Tree Height: {bst.get_height(bst.root)}")

    print("\n--- Deleting node 30 (Has two children: 20 and 40) ---")
    bst.delete(30)
    bst.traverse_in_order(bst.root)  # 20 40 50 60 70 80
    print()
