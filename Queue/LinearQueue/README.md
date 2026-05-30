# LinearQueue

**LinearQueue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. In a linear queue, elements are inserted from one end called the **Rear** (or Back) and are deleted from the other end called the **Front** (or Head).

[Image of linear queue data structure operations enqueue and dequeue]

---

## Core Operations

A LinearQueue supports the following operations:

| Function | Description |
|----------|------------|
| `enqueue(value)` | Adds an element to the rear of the queue. Raises an error if the queue is full (**Overflow**). |
| `dequeue()` | Removes and returns the element at the front of the queue. Raises an error if the queue is empty (**Underflow**). |
| `peek()` / `front()` | Returns the front element without removing it. |
| `isEmpty()` | Checks if the queue has no elements. |
| `isFull()` | Checks if the queue has reached its maximum allocated capacity. |
| `size()` | Returns the current number of elements in the queue. |
| `print()` | Displays the elements of the queue from front to rear. |

---

## Complexity

* **Time Complexity:** - `enqueue`: $O(1)$ constant time, as it only increments the rear index.
  - `dequeue`: $O(1)$ if using indices (pointers) for both front and rear, or $O(n)$ if elements are shifted forward upon every deletion.
* **Space Complexity:** $O(N)$, where $N$ is the total predefined capacity of the queue.

---

## Limitation of a Linear Queue (False Overflow)

A major drawback of a static linear queue is that even if there is empty space available at the front (due to previous `dequeue` operations), once the `rear` index reaches the maximum capacity, no more elements can be inserted. This condition is known as **False Overflow**. 

To resolve this issue, elements either need to be shifted (costly $O(n)$ operation) or a **Circular Queue** should be used instead.
