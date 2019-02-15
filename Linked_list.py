class Node:
	def __init__(self,data,nxt=None):
		self.data = data
		self.nxt = nxt
	def __repr__(self):
		return str(self.data)

class Linked_list:
	def __init__(self,start=None):
		self.start = start
		self.end = self.start
	def append(self,node):
		if self.start == None and self.end == None:
			self.start = Node(node.data)
			self.end = self.start
			return
		while self.end.nxt != None:
			self.end = self.end.nxt
		self.end.nxt = Node(node.data)
		self.end = self.end.nxt
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


if __name__ == "__main__":
	n1 = Node(1)
	n2 = Node(2)
	n3 = Node(3)
	n4 = Node(4)
	n5 = Node(5)

	ll = Linked_list()
	ll.append(n1)
	ll.append(n2)
	ll.append(n3)
	ll.append(n4)
	ll.append(n5)

	print(ll)
	print()

	ll2 = Linked_list()
	ll2.append(n1)
	ll2.append(n2)
	ll2.append(n4)
	ll2.append(n5)

	print(ll2)
	print()

	print(ll == ll2)