# Priority Queue

A **Priority Queue** is an abstract data type similar to a regular queue or stack data structure, but where each element additionally has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority. If two elements have the same priority, they are served according to their order in the queue (or based on implementation rules).

While a standard queue follows the strict FIFO (First In, First Out) rule, a Priority Queue pops elements based on their critical importance or numeric weight.



---

## Core Operations

A Priority Queue supports the following core operations:

| Function | Description |
|----------|------------|
| `insert(value, priority)` | Inserts an element into the queue with an associated priority weight. |
| `extractMax()` / `dequeue()` | Removes and returns the element with the highest priority. |
| `peek()` / `getMaximum()` | Returns the element with the highest priority without removing it. |
| `isEmpty()` | Checks if the priority queue contains no elements. |
| `size()` | Returns the current total number of elements inside the queue. |
| `print()` | Displays the elements currently inside the queue arranged by priority sequence. |

---

## Structural Implementation Approaches

1. **Unordered Array/List:** Insertion is $O(1)$, but searching and extracting the maximum priority element takes $O(n)$ time.
2. **Ordered Array/List:** Elements are kept sorted. Insertion takes $O(n)$ due to element shifting, but extraction is highly efficient at $O(1)$.
3. **Binary Heap (Most Common):** Implemented using a Max-Heap or Min-Heap balanced binary tree structure. Both insertion and extraction run efficiently in $O(\log n)$ logarithmic time.

---

## Complexity (Binary Heap Approach)

* **Time Complexity:** - `insert`: $O(\log n)$
  - `extractMax`: $O(\log n)$
  - `peek`: $O(1)$
* **Space Complexity:** $O(n)$ auxiliary space to hold the element-priority pairings.
