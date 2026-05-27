# SkipList

**SkipList** is a probabilistic data structure that allows fast search, insertion, and deletion operations within an ordered sequence of elements. It can be visualized as a layered set of linked lists, where the bottom layer is a standard ordered linked list, and each higher layer acts as an "express lane" that skips over multiple nodes.

The structure relies on a random coin flip (or probabilistic distribution) to determine how many levels a newly inserted node will propagate upward.

---

## Core Operations

A SkipList supports the following operations:

| Function | Description |
|----------|------------|
| `prepend(value)` | Adds a node at the beginning of the list (forces lower than current elements or acts as a minimum sentinel bound) |
| `append(value)` | Adds a node at the end of the list |
| `insert(value)` | Inserts a node dynamically, generating its probabilistic level height |
| `delete(value)` | Deletes a node by its value from all the levels it resides in |
| `search(value)` | Searches for a value and returns the node or its presence boolean |
| `print()` | Displays all layers of the skip list, showing the "express lanes" |

---

## Complexity

* **Worst Case Time Complexity:** $O(n)$  
  Occurs if the coin flips repeatedly yield the maximum level for all nodes, turning the structure into multiple identical linked lists. However, the probability of this happening for a large $n$ is infinitesimally small.
* **Average Case Time Complexity:** $O(\log n)$  
  Behaves exactly like a binary search or a balanced binary search tree for lookup, insertion, and deletion.
* **Space Complexity:** $O(n)$ on average.  
  The expected total number of nodes is bounded by $2n$ when using a promotion probability of $p = 0.5$.

---

## Advantages

- Much simpler to implement than balanced trees (no complex rotations like in AVL or Red-Black trees).
- Highly concurrent-friendly, as lock-free modifications are easier to implement on linked structures than on trees.
- Provides predictable and efficient average-case performance.

---

## Conceptual Structure
