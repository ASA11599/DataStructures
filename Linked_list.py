class Node:
	def __init__(self,data,nxt=None):
		self.data = data
		self.nxt = nxt
	def __repr__(self):
		return str(self.data)
	def __eq__(self,other):
		if other == None:
			return False
		return self.data == other.data

class Linked_list:
	def __init__(self):
		self.start = None
		self.end = self.start
		self.length = 0
	def __repr__(self):
		s = "LL(" + str(self.start)
		current = self.start
		while current.nxt != None:
			s += "," + str(current.nxt)
			current = current.nxt
		return s + ")"
	def __eq__(self,other):
		current_this = self.start
		current_other = other.start
		while (current_this.nxt != None) or (current_other.nxt != None):
			if current_this.data != current_other.data:
				return False
			current_this = current_this.nxt
			current_other = current_other.nxt
		return True
	def append(self,obj):
		if self.start == None and self.end == None:
			self.start = Node(obj)
			self.end = self.start
			self.length += 1
			return
		while self.end.nxt != None:
			self.end = self.end.nxt
		self.length += 1
		self.end.nxt = Node(obj)
		self.end = self.end.nxt


if __name__ == "__main__":

	ll = Linked_list()
	ll.append(1)
	ll.append(2)
	ll.append(3)
	ll.append(4)
	ll.append(5)

	print(ll)
	print()

	ll2 = Linked_list()
	ll2.append(1)
	ll2.append(2)
	ll2.append(4)
	ll2.append(5)

	print(ll2)
	print()

	print(ll == ll2)