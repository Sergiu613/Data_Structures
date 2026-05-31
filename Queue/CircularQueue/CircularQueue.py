class CircularQueue:
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
        
        self.rear_idx = (self.rear_idx + 1) % self.capacity
        self.queue[self.rear_idx] = value
        self.current_size += 1
        return True

    def dequeue(self):
        if self.isEmpty():
            print("Queue Underflow! Cannot dequeue")
            return None
        value = self.queue[self.front_idx]
        self.queue[self.front_idx] = None
        self.front_idx = (self.front_idx + 1) % self.capacity
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
        elements = []
        for i in range(self.current_size):
            idx = (self.front_idx + i) % self.capacity
            elements.append(str(self.queue[idx]))
        print(" -> ".join(elements))

if __name__ == "__main__":
    q = CircularQueue(3)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.print()  # 10 -> 20 -> 30

    print("Dequeued:", q.dequeue())  # 10
    q.enqueue(40)  # 40
    q.print()  # 20 -> 30 -> 40
