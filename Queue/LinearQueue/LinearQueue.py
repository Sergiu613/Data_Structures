class LinearQueue:
    def __init__(self, capacity=5):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front_idx = 0
        self.rear_idx = -1
        self.current_size = 0

    def isFull(self):
        return self.current_size == self.capacity

    def isEmpty(self):
        return self.current_size == 0

    def enqueue(self, value):
        if self.isFull():
            print(f"Queue Overflow! Cannot enqueue {value}")
            return False
        self.rear_idx += 1
        self.queue[self.rear_idx] = value
        self.current_size += 1
        return True

    def dequeue(self):
        if self.isEmpty():
            print("Queue Underflow! Cannot dequeue")
            return None
        value = self.queue[self.front_idx]
        self.queue[self.front_idx] = None  
        self.front_idx += 1
        self.current_size -= 1
        return value

    def peek(self):
        if self.isEmpty():
            print("Queue is empty!")
            return None
        return self.queue[self.front_idx]

    def size(self):
        return self.current_size

    def print(self):
        if self.isEmpty():
            print("Queue is empty")
            return
        print("Queue (Front -> Rear): ", end="")
        elements = [str(self.queue[i]) for i in range(self.front_idx, self.rear_idx + 1)]
        print(" -> ".join(elements))

if __name__ == "__main__":
    q = LinearQueue(3)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)  # Overflow
    q.print()

    print("Dequeued:", q.dequeue())
    print("Front element:", q.peek())
    q.print()
