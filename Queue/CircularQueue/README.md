# CircularQueue

**CircularQueue** is an extended and optimized version of a linear queue that follows the **FIFO (First In, First Out)** principle. In a standard linear queue, once the pointer reaches the end of the array, no more insertions are allowed even if there is free space at the front. A circular queue solves this by wrapping the indexes around to the beginning using modulo arithmetic (`%`).

Conceptual layout connects the last position back to the first position, forming a continuous ring buffer.



---

## Core Operations

A CircularQueue supports the following operations:

| Function | Description |
|----------|------------|
| `enqueue(value)` | Adds an element to the rear of the circular queue. Performs index wrap-around. Raises an error if full. |
| `dequeue()` | Removes and returns the element at the front. Frees up slots for subsequent wrap-around insertions. |
| `peek()` / `front()` | Returns the front element without removing it. |
| `isEmpty()` | Checks if the queue has no elements. |
| `isFull()` | Checks if the current count of elements matches the maximum allocated capacity. |
| `size()` | Returns the exact number of elements currently stored. |
| `print()` | Displays the active elements from front to rear sequence. |

---

## Complexity

* **Time Complexity:** $O(1)$ constant time for all operations (`enqueue`, `dequeue`, `peek`, `isEmpty`, `isFull`). Modulo equations find boundaries instantly.
* **Space Complexity:** $O(N)$, where $N$ is the fixed array capacity allocated upfront.

---

## Advantages over Linear Queue

1. **Memory Efficiency:** No memory is wasted. Vacated spaces at the front from `dequeue` actions can be dynamically reused.
2. **Fixed Overhead:** Operates at max capacity without requiring expensive element shifting operations ($O(n)$) to reset indexes.
