class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class DynamicStack:
    def __init__(self):
        self.top_node = None
        self.stack_size = 0

    def isEmpty(self):
        return self.top_node is None

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top_node
        self.top_node = new_node
        self.stack_size += 1

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow! Cannot pop")
            return None
        popped_value = self.top_node.value
        self.top_node = self.top_node.next
        self.stack_size -= 1
        return popped_value

    def peek(self):
        if self.isEmpty():
            print("Stack is empty!")
            return None
        return self.top_node.value

    def size(self):
        return self.stack_size

    def print(self):
        if self.isEmpty():
            print("Stack is empty")
            return
        print("Stack (Top -> Bottom):")
        current = self.top_node
        while current:
            print(f"| {current.value} |")
            current = current.next
        print("-------")

if __name__ == "__main__":
    stack = DynamicStack()
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.print()

    print("Popped:", stack.pop())
    print("Top element:", stack.peek())
    print("Current size:", stack.size())
    stack.print()
