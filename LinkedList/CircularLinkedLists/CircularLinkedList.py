class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def prepend(self, value):
        new_node = Node(value)
        if not self.head:
            new_node.next = new_node
            self.head = new_node
            return
        
        current = self.head
        while current.next != self.head:
            current = current.next
        
        new_node.next = self.head
        current.next = new_node
        self.head = new_node

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            new_node.next = new_node
            self.head = new_node
            return
        
        current = self.head
        while current.next != self.head:
            current = current.next
        
        current.next = new_node
        new_node.next = self.head

    def insert(self, value, position):
        if position == 0:
            self.prepend(value)
            return
        
        new_node = Node(value)
        current = self.head
        for _ in range(position - 1):
            current = current.next
            if current == self.head:
                raise IndexError("Position out of bounds")
        
        new_node.next = current.next
        current.next = new_node

    def deleteFirst(self):
        if not self.head:
            return
        if self.head.next == self.head:
            self.head = None
            return
        
        current = self.head
        while current.next != self.head:
            current = current.next
            
        current.next = self.head.next
        self.head = self.head.next

    def deleteLast(self):
        if not self.head:
            return
        if self.head.next == self.head:
            self.head = None
            return
        
        current = self.head
        prev = None
        while current.next != self.head:
            prev = current
            current = current.next
            
        prev.next = self.head

    def delete(self, position):
        if not self.head:
            return
        if position == 0:
            self.deleteFirst()
            return
        
        current = self.head
        prev = None
        for _ in range(position):
            prev = current
            current = current.next
            if current == self.head:
                return
                
        prev.next = current.next

    def search(self, value):
        if not self.head:
            return -1
        
        current = self.head
        position = 0
        while True:
            if current.value == value:
                return position
            current = current.next
            position += 1
            if current == self.head:
                break
        return -1

    def print(self):
        if not self.head:
            print("Empty List")
            return
        
        current = self.head
        elements = []
        while True:
            elements.append(str(current.value))
            current = current.next
            if current == self.head:
                break
        print(" -> ".join(elements) + " -> (head)")

if __name__ == "__main__":
    cll = CircularLinkedList()
    cll.append(10)
    cll.append(20)
    cll.prepend(5)
    cll.insert(15, 2)
    cll.print()  # Output: 5 -> 10 -> 15 -> 20 -> (head)
    cll.delete(2)
    cll.print()  # Output: 5 -> 10 -> 20 -> (head)
