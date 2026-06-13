# Min Heap

A **Min Heap** is a specialized, complete binary tree data structure that satisfies the **Heap Property**: the value of each node must be greater than or equal to the value of its parent. Consequently, the absolute **minimum element** within the entire structure is always located at the root node.

Min Heaps are typically implemented using arrays or dynamic vectors because a complete binary tree can be compactly mapped into contiguous memory without requiring child pointers.



---

## Indexing Mathematics (Array-Based)

For any element stored at array index `i` (using 0-based indexing):
- **Parent Node index:** `(i - 1) / 2` (integer division)
- **Left Child index:** `(2 * i) + 1`
- **Right Child index:** `(2 * i) + 2`

---

## Core Operations

A Min Heap supports the following core operations:

| Function | Complexity | Description |
|----------|------------|-------------|
| `insert(value)` | $O(\log n)$ | Adds a new element at the end of the array and moves it up (**bubble-up** / **heapify-up**) until the heap property is restored. |
| `extractMin()` | $O(\log n)$ | Removes and returns the root (minimum) element. The last element replaces the root and sinks down (**bubble-down** / **heapify-down**). |
| `peek()` | $O(1)$ | Returns the root element without removing it. |
| `size()` | $O(1)$ | Returns the current number of elements inside the heap. |
| `print()` | $O(n)$ | Displays the flat array layout representing the heap hierarchy. |

---

## Advantages & Common Applications

- **Priority Queues:** Min Heaps are the default engine behind efficient priority queue implementations.
- **Dijkstra's Shortest Path Algorithm:** Used to quickly extract the vertex with the minimum tentative distance.
- **Heap Sort:** Can be adapted to sort collections efficiently in $O(n \log n)$ time with $O(1)$ auxiliary space.
