class MinHeap:
    def __init__(self):
        self.heap = []

    def size(self):
        return len(self.heap)

    def peek(self):
        if self.size() == 0:
            return None
        return self.heap[0]

    def _parent(self, i): return (i - 1) // 2
    def _left_child(self, i): return (2 * i) + 1
    def _right_child(self, i): return (2 * i) + 2

    def insert(self, value):
        self.heap.append(value)
        self._heapify_up(self.size() - 1)

    def _heapify_up(self, i):
        while i > 0 and self.heap[i] < self.heap[self._parent(i)]:
            parent_idx = self._parent(i)
            # Swap
            self.heap[i], self.heap[parent_idx] = self.heap[parent_idx], self.heap[i]
            i = parent_idx

    def extract_min(self):
        if self.size() == 0:
            return None
        if self.size() == 1:
            return self.heap.pop()

        root_val = self.heap[0]
        # Move the last element to the root position
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root_val

    def _heapify_down(self, i):
        smallest = i
        left = self._left_child(i)
        right = self._right_child(i)

        if left < self.size() and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < self.size() and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify_down(smallest)

    def print_heap(self):
        print("Heap Array Layout:", self.heap)

if __name__ == "__main__":
    heap = MinHeap()
    elements = [15, 10, 20, 5, 8]
    for x in elements:
        heap.insert(x)

    heap.print_heap()  # Expected root: 5
    print("Minimum element picked (peek):", heap.peek())
    
    print("Extracted min:", heap.extract_min())  # Removes 5
    heap.print_heap()  # New root should be 8
