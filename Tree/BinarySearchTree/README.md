# Binary Search Tree (BST)

A **Binary Search Tree (BST)** is a node-based binary tree data structure that possesses an internal ordering property. For any given node, it strictly follows these rules:
- The **left subtree** contains only nodes with values **less than** the parent node's value.
- The **right subtree** contains only nodes with values **greater than** the parent node's value.
- Both the left and right subtrees must also be binary search trees.

This attribute allows for highly optimized search, insertion, and deletion operations, mimicking the behavior of a binary search on a sorted array without the associated shifting penalties.

---

## Core Operations

A Binary Search Tree typically supports the following core operations:

| Function | Description |
|----------|------------|
| `insert(value)` | Adds a new node containing the specified value in its mathematically correct sorted location. |
| `search(value)` | Recursively checks the tree to locate a node with the target value. |
| `delete(value)` | Removes a target node while reorganizing remaining structural links to maintain the BST property. |
| `traverseInOrder()` | Displays the elements of the BST in perfect non-decreasing sorted order. |

---

## Structural Dynamics

When you perform an **In-Order traversal** (Left, Root, Right) on a Binary Search Tree, it will always output the dataset in a **sorted, ascending sequence**.

---

## Complexity

* **Time Complexity:** - **Average Case:** $O(\log n)$ for search, insertion, and deletion when the tree is reasonably balanced.
  - **Worst Case:** $O(n)$ if elements are inserted in a sorted or near-sorted order (e.g., $1, 2, 3, 4, 5$). This turns the tree into a skewed single linear chain (degraded into a standard linked list).
* **Space Complexity:** $O(h)$ auxiliary stack space for recursion, where $h$ represents the maximum height of the tree.
