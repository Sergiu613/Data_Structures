# Binary Tree

A **Binary Tree** is a hierarchical, non-linear data structure in which each node has at most **two children**, referred to as the **Left Child** and the **Right Child**. It forms the foundational basis for more advanced data structures like Binary Search Trees (BST), AVL trees, and Heaps.

Binary Trees are widely used for representing expressions, hierarchical data categorization, and enabling efficient search operations.

---

## Core Operations

A Binary Tree typically supports the following core operations:

| Function | Description |
|----------|------------|
| `createNode(value)` | Allocates and initializes a new node with data, setting both child pointers to `NULL`/`None`. |
| `traverseInOrder()` | Traverses the tree in Left-Root-Right sequence. |
| `traversePreOrder()` | Traverses the tree in Root-Left-Right sequence. |
| `traversePostOrder()` | Traverses the tree in Left-Right-Root sequence. |
| `print()` | Displays the layout or nodes of the tree. |

---

## Tree Traversal Overview



1. **In-Order (Left, Root, Right):** Used to get nodes in non-decreasing order in Binary Search Trees.
2. **Pre-Order (Root, Left, Right):** Used to create a copy of the tree or get prefix expressions.
3. **Post-Order (Left, Right, Root):** Used to delete the tree or get postfix expressions.

---

## Complexity

* **Time Complexity:** - `Traversal` (In/Pre/Post-Order): $O(n)$ because every single node must be visited exactly once.
* **Space Complexity:** $O(h)$ auxiliary stack space for recursion, where $h$ is the maximum height of the tree. In the worst case (a highly skewed tree), $h = n$. In the best balanced case, $h = \log n$.
