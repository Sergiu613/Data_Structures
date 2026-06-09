# General Tree (N-ary Tree)

A **General Tree** is a non-linear, hierarchical data structure where each node can have an **arbitrary number of children**. Unlike a Binary Tree, which strictly limits each node to a maximum of two children, a General Tree places no constraint on the number of subnodes/branches a parent node can possess.

It is widely used to represent organizational charts, file directories, HTML DOM structures, and any data with natural family/hierarchical relationships.



---

## Core Operations

A General Tree typically supports the following operations:

| Function | Description |
|----------|------------|
| `createNode(value)` | Allocates and returns a new node holding the specified data value. |
| `addChild(parent, childValue)` | Spawns a new node with `childValue` and adds it to the target parent's list of children. |
| `search(value)` | Searches the tree recursively to locate the node containing the target value. |
| `print()` / `traverse()` | Displays the entire tree structure graphically, usually using Pre-order Depth-First Search (DFS) with visual indentation. |

---

## Common Terminology

* **Root:** The top-most node of the tree from which all other nodes originate. It has no parent.
* **Child:** A node directly connected to another node when moving away from the root.
* **Parent:** The converse notion of a child; a node that links directly to one or more subordinate nodes.
* **Leaf Node:** A terminal node that contains no children.
* **Degree:** The total number of children a specific node has.

---

## Complexity

* **Time Complexity:** - `insert` / `addChild`: $O(1)$ constant time once the parent node is located.
  - `search`: $O(n)$ in the worst case, as every node in the hierarchical tree may need to be visited during a traversal.
  - `print`: $O(n)$ since every node must be evaluated to be displayed.
* **Space Complexity:** $O(n)$ to store the node connections, plus $O(h)$ auxiliary stack space during recursive depth-first searches, where $h$ represents the maximum height of the tree.
