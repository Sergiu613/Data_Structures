class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def prepend(self, value):
        new_node = Node(value)
        if self.head:
            self.head.prev = new_node
            new_node.next = self.head
        self.head = new_node

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
        new_node.prev = current

    def insert(self, value, position):
        if position == 0:
            self.prepend(value)
            return
        new_node = Node(value)
        current = self.head
        for _ in range(position - 1):
            if current is None:
                raise IndexError("Position out of bounds")
            current = current.next
        if current is None:
            raise IndexError("Position out of bounds")
        
        new_node.next = current.next
        new_node.prev = current
        if current.next:
            current.next.prev = new_node
        current.next = new_node

    def deleteFirst(self):
        if not self.head:
            return
        self.head = self.head.next
        if self.head:
            self.head.prev = None

    def deleteLast(self):
        if not self.head:
            return
        if not self.head.next:
            self.head = None
            return
        current = self.head
        while current.next:
            current = current.next
        current.prev.next = None

    def delete(self, position):
        if not self.head:
            return
        if position == 0:
            self.deleteFirst()
            return
        current = self.head
        for _ in range(position):
            if current is None:
                return
            current = current.next
        if current is None:
            return
        
        if current.prev:
            current.prev.next = current.next
        if current.next:
            current.next.prev = current.prev

    def search(self, value):
        current = self.head
        position = 0
        while current:
            if current.value == value:
                return position
            current = current.next
            position += 1
        return -1

    def print(self):
        current = self.head
        elements = []
        while current:
            elements.append(str(current.value))
            current = current.next
        print(" <-> ".join(elements) if elements else "Empty List")

if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.append(10)
    dll.append(20)
    dll.prepend(5)
    dll.insert(15, 2)
    dll.print()  # Output: 5 <-> 10 <-> 15 <-> 20
    dll.delete(2)
    dll.print()  # Output: 5 <-> 10 <-> 20
