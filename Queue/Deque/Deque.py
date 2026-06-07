class Deque:
    def __init__(self, capacity=5):
        self.capacity = capacity
        self.arr = [None] * capacity
        self.front = -1
        self.rear = 0
        self.current_size = 0

    def isFull(self):
        return self.current_size == self.capacity

    def isEmpty(self):
        return self.current_size == 0

    def insertFront(self, value):
        if self.isFull():
            print(f"Deque Overflow! Cannot insert {value} at Front")
            return False
        
        if self.front == -1:  
            self.front = 0
            self.rear = 0
        else:
            self.front = (self.front - 1 + self.capacity) % self.capacity
            
        self.arr[self.front] = value
        self.current_size += 1
        return True

    def insertRear(self, value):
        if self.isFull():
            print(f"Deque Overflow! Cannot insert {value} at Rear")
            return False
            
        if self.front == -1:
            self.front = 0
            self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.capacity
            
        self.arr[self.rear] = value
        self.current_size += 1
        return True

    def deleteFront(self):
        if self.isEmpty():
            print("Deque Underflow! Cannot delete from Front")
            return None
            
        value = self.arr[self.front]
        self.arr[self.front] = None
        
        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
            
        self.current_size -= 1
        return value

    def deleteRear(self):
        if self.isEmpty():
            print("Deque Underflow! Cannot delete from Rear")
            return None
            
        value = self.arr[self.rear]
        self.arr[self.rear] = None
        
        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.rear = (self.rear - 1 + self.capacity) % self.capacity
            
        self.current_size -= 1
        return value

    def getFront(self):
        if self.isEmpty():
            return None
        return self.arr[self.front]

    def getRear(self):
        if self.isEmpty():
            return None
        return self.arr[self.rear]

    def print(self):
        if self.isEmpty():
            print("Deque is empty")
            return
        print("Deque (Front -> Rear): ", end="")
        elements = []
        for i in range(self.current_size):
            idx = (self.front + i) % self.capacity
            elements.append(str(self.arr[idx]))
        print(" <-> ".join(elements))

if __name__ == "__main__":
    dq = Deque(4)
    dq.insertRear(10)
    dq.insertRear(20)
    dq.insertFront(5)
    dq.print()  # 5 <-> 10 <-> 20
    
    dq.insertRear(30)
    dq.print()  # 5 <-> 10 <-> 20 <-> 30
    
    print("Deleted from Rear:", dq.deleteRear())  # 30
    print("Deleted from Front:", dq.deleteFront())  # 5
    dq.print()  # 10 <-> 20
