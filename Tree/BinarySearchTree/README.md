# Binary Search Tree (BST)

A **Binary Search Tree (BST)** is an organized, node-based binary tree data structure. It maintains a strict internal sorting property that guarantees optimal data layout for quick execution.

## Architectural Constraints

For any given parent node within the tree structure:
- The **left subtree** houses only nodes with values **strictly less than** the parent's value.
- The **right subtree** houses only nodes with values **strictly greater than** the parent's value.
- Every individual left and right subtree must inherently be a valid binary search tree itself.



---

## Supported Operations

This repository contains a full-featured implementation covering both basic and advanced structural operations:

| Function | Complexity | Description |
|----------|------------|-------------|
| `insert(value)` | $O(\log n)$ average | Dynamically navigates the constraints to insert a value into its correct mathematical sequence. |
| `search(value)` | $O(\log n)$ average | Performs an optimized binary elimination hunt across the levels to find a target value. |
| `delete(value)` | $O(\log n)$ average | Removes an element. Handles complex link re-wiring for leaves, single-child nodes, and dual-child nodes. |
| `findMin()` | $O(\log n)$ average | Deep dives down the leftmost path of the structure to extract the minimum value. |
| `findMax()` | $O(\log n)$ average | Deep dives down the rightmost path of the structure to extract the maximum value. |
| `getHeight()` | $O(n)$ | Recursively evaluates branch depths to return the maximum height from the root. |
| `traverseInOrder()`| $O(n)$ | Processes the layout in a **Left-Root-Right** chain, yielding an ascending sorted order. |

---

## Deletion Mechanics

Deleting a node requires restructuring pointer references to preserve the BST invariants. The algorithm evaluates three core structural cases:

1. **Node is a Leaf (Zero Children):** The target node is decoupled and safely freed; its parent's respective link is set to `NULL`.
2. **Node has One Child:** The single child bypasses the parent, linking directly to the grandparent node.
3. **Node has Two Children:** The node is replaced by its **In-Order Successor** (the absolute minimum node inside its right subtree). The original successor node is then recursively purged from the right branch.

---

## Complexity Analysis

| Scenario | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| **Average Case** | $O(\log n)$ | $O(h)$ recursion stack space ($h = \log n$) |
| **Worst Case** | $O(n)$ | $O(n)$ call stack depth |

> **Note on Worst Case Performance:** If data is fed into the tree in a pre-sorted sequential manner (e.g., `10, 20, 30, 40`), the BST degrades into a linear single chain (functionally equivalent to a standard Singly Linked List). To mitigate this, self-balancing architectures like AVL Trees or Red-Black Trees are used.
