class Queue:

    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self,item):
        self.items.append(item)

    def dequeue(self):
        temp = self.items[0]
        del self.items[0]
        return temp

    def __eq__(self,other):
        if len(self.items) != len(other.items):
            return False
        for i in range(len(self)):
            if self.items[i] != other.items[i]:
                return False
        return True

    def __str__(self):
        return str(self.items)