class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

class GeneralTree:
    def __init__(self, root_value):
        self.root = TreeNode(root_value)

    def search_node(self, current_node, value):
        if current_node is None:
            return None
        if current_node.value == value:
            return current_node
        

        for child in current_node.children:
            found = self.search_node(child, value)
            if found:
                return found
        return None

    def add_child(self, parent_value, child_value):
        parent_node = self.search_node(self.root, parent_value)
        if parent_node:
            new_child = TreeNode(child_value)
            parent_node.children.append(new_child)
            return True
        print(f"Parent '{parent_value}' not found!")
        return False

    def print_tree(self, node=None, level=0):
        if node is None and level == 0:
            node = self.root
            
        print("  " * level + "|-- " + str(node.value))
        for child in node.children:
            self.print_tree(child, level + 1)

if __name__ == "__main__":
    tree = GeneralTree("Root")
    tree.add_child("Root", "Folder_A")
    tree.add_child("Root", "Folder_B")
    tree.add_child("Folder_A", "File_A1")
    tree.add_child("Folder_A", "File_A2")
    tree.add_child("Folder_B", "File_B1")
    
    tree.print_tree()
