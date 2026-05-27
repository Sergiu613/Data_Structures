import random

class SkipNode:
    def __init__(self, value, level):
        self.value = value
        self.next = [None] * (level + 1)

class SkipList:
    def __init__(self, max_level=4, p=0.5):
        self.max_level = max_level
        self.p = p
        self.header = SkipNode(float('-inf'), self.max_level)
        self.level = 0

    def random_level(self):
        lvl = 0
        while random.random() < self.p and lvl < self.max_level:
            lvl += 1
        return lvl

    def insert(self, value):
        update = [None] * (self.max_level + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.next[i] and current.next[i].value < value:
                current = current.next[i]
            update[i] = current

        current = current.next[0]

        if current is None or current.value != value:
            rlevel = self.random_level()

            if rlevel > self.level:
                for i in range(self.level + 1, rlevel + 1):
                    update[i] = self.header
                self.level = rlevel

            new_node = SkipNode(value, rlevel)

            for i in range(rlevel + 1):
                new_node.next[i] = update[i].next[i]
                update[i].next[i] = new_node

    def append(self, value):
        self.insert(value)

    def prepend(self, value):
        self.insert(value)

    def delete(self, value):
        update = [None] * (self.max_level + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.next[i] and current.next[i].value < value:
                current = current.next[i]
            update[i] = current

        current = current.next[0]

        if current and current.value == value:
            for i in range(self.level + 1):
                if update[i].next[i] != current:
                    break
                update[i].next[i] = current.next[i]

            while self.level > 0 and self.header.next[self.level] is None:
                self.level -= 1

    def search(self, value):
        current = self.header
        for i in range(self.level, -1, -1):
            while current.next[i] and current.next[i].value < value:
                current = current.next[i]
        current = current.next[0]
        return current is not None and current.value == value

    def print(self):
        print("\n--- Skip List Levels ---")
        for lvl in range(self.level, -1, -1):
            print(f"Level {lvl}: ", end="")
            node = self.header.next[lvl]
            while node:
                print(f"{node.value} -> ", end="")
                node = node.next[lvl]
            print("None")

if __name__ == "__main__":
    sl = SkipList()
    sl.insert(3)
    sl.insert(6)
    sl.insert(7)
    sl.insert(9)
    sl.insert(12)
    sl.print()

    print(f"Searching for 7: {sl.search(7)}")
    sl.delete(7)
    sl.print()
