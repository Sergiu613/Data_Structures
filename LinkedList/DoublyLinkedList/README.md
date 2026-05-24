# DoublyLinkedList

**DoublyLinkedList** is an extension of a linked list that allows bidirectional traversal. This data structure stores elements in a linear order, where each node contains:

- **the data value** (`value`)  
- **a reference to the next node** (`next`)  
- **a reference to the previous node** (`prev`)  

The first node's `prev` pointer and the last node's `next` pointer point to the end of the list (`NULL` or `None` depending on the language).

---

## Core Operations

A DoublyLinkedList supports the following operations:

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

- Can be traversed in both forward and backward directions  
- Deletion operations can be more efficient than in a single linked list if a pointer to the node to be deleted is given  
- Efficient insertion and deletion at both the beginning and the end of the list  
- Implementable in any language that supports structures and references/pointers (`C`, `C++`, `Java`, `Python`, etc.)

---

## Conceptual Structure
