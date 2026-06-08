class Element:
    def __init__(self, value, priority):
        self.value = value
        self.priority = priority

class PriorityQueue:
    def __init__(self):
        self.queue = []

    def isEmpty(self):
        return len(self.queue) == 0

    def insert(self, value, priority):
        new_element = Element(value, priority)
        inserted = False
        for i in range(len(self.queue)):
            if self.queue[i].priority < priority:
                self.queue.insert(i, new_element)
                inserted = True
                break
        if not inserted:
            self.queue.append(new_element)

    def dequeue(self):
        if self.isEmpty():
            print("Priority Queue Underflow! Cannot dequeue")
            return None
        return self.queue.pop(0).value

    def peek(self):
        if self.isEmpty():
            print("Priority Queue is empty!")
            return None
        return self.queue[0].value

    def size(self):
        return len(self.queue)

    def print(self):
        if self.isEmpty():
            print("Priority Queue is empty")
            return
        print("Priority Queue (Highest -> Lowest Priority):")
        for item in self.queue:
            print(f"[Value: {item.value}, Priority: {item.priority}]", end=" ")
        print()

if __name__ == "__main__":
    pq = PriorityQueue()
    pq.insert("Task Low", 1)
    pq.insert("Task High", 5)
    pq.insert("Task Medium", 3)
    pq.print()  # High (5) -> Medium (3) -> Low (1)

    print("Dequeued highest priority:", pq.dequeue())  # Task High
    pq.print()  # Medium (3) -> Low (1)
