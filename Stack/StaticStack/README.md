# StaticStack

**StaticStack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. It has a fixed size determined at the time of creation, meaning it is implemented using a fixed-size contiguous memory block (an array). 

The most recently added element is at the "top" of the stack and is the first one to be removed.



---

## Core Operations

A StaticStack supports the following operations:

| Function | Description |
|----------|------------|
| `push(value)` | Adds an element to the top of the stack. Raises an error if the stack is full (**Overflow**). |
| `pop()` | Removes and returns the top element of the stack. Raises an error if the stack is empty (**Underflow**). |
| `peek()` / `top()` | Returns the top element without removing it. |
| `isEmpty()` | Checks if the stack has no elements. |
| `isFull()` | Checks if the stack has reached its maximum allocated capacity. |
| `size()` | Returns the current number of elements in the stack. |
| `print()` | Displays the elements of the stack from top to bottom. |

---

## Complexity

* **Time Complexity:** $O(1)$ for all core operations (`push`, `pop`, `peek`, `isEmpty`, `isFull`). Since elements are accessed directly via an array index, no shifting or iteration is required.
* **Space Complexity:** $O(N)$, where $N$ is the maximum capacity predefined for the array. Memory is allocated upfront, regardless of how many elements are currently inside.

---

## Advantages & Disadvantages

* **Advantages:**
  - Extremely fast and efficient ($O(1)$ constant time).
  - Memory consumption is predictable since it has a rigid limit.
  - No allocation overhead at runtime (ideal for embedded or real-time systems).

* **Disadvantages:**
  - Fixed capacity; if the stack fills up, it cannot expand dynamically to fit more data.
  - Potential waste of memory if the allocated size is much larger than the actual number of elements used.
