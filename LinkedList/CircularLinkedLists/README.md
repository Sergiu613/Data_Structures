# CircularLinkedList

**CircularLinkedList** is a variation of a linked list where all nodes are connected to form a circle. There is no `NULL` or `None` at the end of the list. Instead, each node contains:

- **the data value** (`value`)  
- **a reference to the next node** (`next`)  

The `next` pointer of the last node points back to the first node (`head`) of the list.

---

## Core Operations

A CircularLinkedList supports the following operations:

| Function | Description |
|----------|------------|
| `prepend(value)` | Adds a node at the beginning of the list |
| `append(value)` | Adds a node at the end of the list |
| `insert(value, position)` | Inserts a node at a specific position |
| `deleteFirst()` | Deletes the first node |
| `deleteLast()` | Deletes the last node |
| `delete(position)` | Deletes the node at a specific position |
| `search(value)` | Searches for a node by value and returns its position |
| `print()` | Displays the list in order, from first to last node |

---

## Advantages

- Any node can be a starting point to traverse the entire list.
- Useful for implementing queue data structures or in applications where components need to be stepped through repeatedly in a loop (e.g., CPU scheduling algorithms, multiplayer turn-based games).
- Elimination of edge cases regarding `NULL` pointer exceptions during complete traversal.

---

## Conceptual Structure
