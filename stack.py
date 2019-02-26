class Stack:

	def __init__(self):
		self.items = []

	def is_empty(self):
		return len(self.items) == 0

	def push(self,item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def __eq__(self,other):
		if len(self.items) != len(other.items):
			return False
		for i in range(len(self.items)):
			if self.items[i] != other.items[i]:
				return False
		return True

	def __repr__(self):
		return str(self.items)