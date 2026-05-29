# DynamicStack

**DynamicStack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. Unlike a static stack, a dynamic stack does not have a fixed upper bound on its capacity. It grows and shrinks dynamically at runtime, adjusting its memory footprint based on the number of elements it holds.

It is typically implemented using a **linked list**, where each node points to the one beneath it, and the `head` pointer represents the `top` of the stack.

---

## Core Operations

A DynamicStack supports the following operations:

| Function | Description |
|----------|------------|
| `push(value)` | Allocates memory for a new element and places it at the top of the stack. |
| `pop()` | Removes and returns the top element. Frees the associated memory. Raises an error if the stack is empty (**Underflow**). |
| `peek()` / `top()` | Returns the top element without removing it. |
| `isEmpty()` | Checks if the stack contains no elements. |
| `size()` | Returns the current number of elements stored in the stack. |
| `print()` | Displays the elements of the stack from top to bottom. |

---

## Complexity

* **Time Complexity:** $O(1)$ for all core operations (`push`, `pop`, `peek`, `isEmpty`). Memory allocation or node reference swaps happen in constant time without traversing the structure.
* **Space Complexity:** $O(n)$, where $n$ is the current number of elements in the stack. Memory is allocated on-demand per element, meaning there is no wasted memory upfront.

---

## Advantages & Disadvantages

* **Advantages:**
  - **No Size Limitations:** The stack can grow as long as the system has free memory.
  - **Memory Efficiency:** It only occupies as much memory as needed by the actual elements present.
  - No risk of a "Stack Overflow" due to artificial limits (only due to hardware memory exhaustion).

* **Disadvantages:**
  - Slight memory overhead because each node must store an extra pointer/reference (`next`).
  - Runtime execution can be marginally slower than static arrays due to dynamic memory allocations (`malloc`/`new`) and pointer dereferencing.
