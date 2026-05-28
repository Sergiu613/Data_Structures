class StaticStack:
    def __init__(self, capacity=5):
        self.capacity = capacity
        self.stack = [None] * capacity
        self.top_idx = -1  # Indică indexul elementului de sus

    def isFull(self):
        return self.top_idx == self.capacity - 1

    def isEmpty(self):
        return self.top_idx == -1

    def push(self, value):
        if self.isFull():
            print("Stack Overflow! Cannot push", value)
            return False
        self.top_idx += 1
        self.stack[self.top_idx] = value
        return True

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow! Cannot pop")
            return None
        value = self.stack[self.top_idx]
        self.stack[self.top_idx] = None  
        self.top_idx -= 1
        return value

    def peek(self):
        if self.isEmpty():
            print("Stack is empty!")
            return None
        return self.stack[self.top_idx]

    def size(self):
        return self.top_idx + 1

    def print(self):
        if self.isEmpty():
            print("Stack is empty")
            return
        print("Stack (Top -> Bottom):")
        for i in range(self.top_idx, -1, -1):
            print(f"| {self.stack[i]} |")
        print("-------")

if __name__ == "__main__":
    stack = StaticStack(3)
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.push(40)  # Overflow
    stack.print()

    print("Popped:", stack.pop())
    print("Top element:", stack.peek())
    stack.print()
