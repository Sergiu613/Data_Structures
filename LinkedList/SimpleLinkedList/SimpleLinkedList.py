class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class SimpleLinkedList:
    def __init__(self):
        self.head = None

    def prepend(self, value):
        new_node = Node(value)
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
        current.next = new_node

    def deleteFirst(self):
        if not self.head:
            return
        self.head = self.head.next

    def deleteLast(self):
        if not self.head:
            return
        if not self.head.next:
            self.head = None
            return
        current = self.head
        while current.next.next:
            current = current.next
        current.next = None

    def delete(self, position):
        if not self.head:
            return
        if position == 0:
            self.deleteFirst()
            return
        current = self.head
        for _ in range(position - 1):
            if current.next is None:
                return
            current = current.next
        if current.next is None:
            return
        current.next = current.next.next

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
        print(" -> ".join(elements) if elements else "Empty List")

if __name__ == "__main__":
    ll = SimpleLinkedList()
    ll.append(10)
    ll.append(20)
    ll.prepend(5)
    ll.insert(15, 2)
    ll.print()
    print(f"Position of 15: {ll.search(15)}")
    ll.delete(2)
    ll.print()
