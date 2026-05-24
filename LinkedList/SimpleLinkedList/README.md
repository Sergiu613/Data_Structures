# SimpleLinkedList

**SimpleLinkedList** is a basic implementation of a **linked list** that can be implemented in any programming language. This data structure stores elements in a linear order, where each node contains:

- **the data value** (`value`)  
- **a reference to the next node** (`next`)  

The last node points to the end of the list (`NULL` or `None` depending on the language).

---

## Core Operations

A SimpleLinkedList typically supports the following operations:

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

- Simple and easy to understand, ideal for beginners  
- Efficient insertion and deletion at the beginning  
- Can be extended to **doubly linked lists** or **circular lists**  
- Implementable in any language that supports structures and references/pointers (`C`, `C++`, `Java`, `Python`, etc.)

---

## Conceptual Structure

