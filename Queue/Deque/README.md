# Double-Ended Queue (Deque)

**Deque** (pronounced *'deck'*) stands for **Double-Ended Queue**. It is a generalized linear data structure that allows insertion and deletion of elements from both ends: the **Front** (Head) and the **Rear** (Tail). 

Because it supports operations at both boundaries, a Deque can be configured to behave either as a **Queue (FIFO)** or as a **Stack (LIFO)** depending on which subset of functions you invoke.



---

## Core Operations

A Deque supports the following core operations:

| Function | Description |
|----------|------------|
| `insertFront(value)` | Adds an element at the front of the Deque. Performs index wrap-around. Raises an error if full (**Overflow**). |
| `insertRear(value)` | Adds an element at the rear of the Deque. Same as standard `enqueue`. Raises an error if full (**Overflow**). |
| `deleteFront()` | Removes and returns the element at the front. Same as standard `dequeue`. Raises an error if empty (**Underflow**). |
| `deleteRear()` | Removes and returns the element at the rear. Raises an error if empty (**Underflow**). |
| `getFront()` / `peekFront()` | Returns the front element without removing it. |
| `getRear()` / `peekRear()` | Returns the rear element without removing it. |
| `isEmpty()` | Checks if the Deque contains no elements. |
| `isFull()` | Checks if the Deque has reached its allocated maximum capacity. |
| `size()` | Returns the current total count of active elements. |
| `print()` | Displays elements sequentially from Front to Rear. |

---

## Complexity

* **Time Complexity:** $O(1)$ constant time for all insertion and deletion operations (`insertFront`, `insertRear`, `deleteFront`, `deleteRear`). This is achieved through the use of circular array mechanics or bidirectional references.
* **Space Complexity:** $O(N)$, where $N$ represents the maximum bounds of allocated buffer slots.

---

## Variants of Deque

1. **Input-Restricted Deque:** Insertion is allowed at only one end (e.g., Rear only), but deletion can be performed from both ends (Front and Rear).
2. **Output-Restricted Deque:** Deletion is allowed at only one end (e.g., Front only), but insertion can be performed at both ends (Front and Rear).

---

## Advantages

- **Versatility:** Can act as both a stack and a queue, making it a highly adaptable hybrid structure.
- **Efficiency:** Offers $O(1)$ time complexity for boundary operations, which is ideal for sliding window problems, undo/redo features, or managing history browser states.
- **No Shifting Overhead:** When implemented with a circular buffer or a doubly linked list, it completely eliminates the need to shift elements when inserting or removing from the front.
