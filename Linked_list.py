class Node:
	def __init__(self,data,nxt=None):
		self.data = data
		self.nxt = nxt
	def __repr__(self):
		return str(self.data)
	def __eq__(self,other):
		if other == None:
			return False
		return self.data == other

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
	def delete(self,obj):
		if self.start.data == obj:
			self.start = self.start.nxt
		current = self.start
		while current.nxt != obj:
			current = current.nxt
		current.nxt = current.nxt.nxt
		self.length += 1
	def get(self,index):
		current_index = 0
		current = self.start
		while current_index <= self.length:
			if current_index == index:
				return current
			current_index += 1
			current = current.nxt




if __name__ == "__main__":

	ll = Linked_list()
	ll.append(1)
	ll.append(2)
	ll.append(3)
	ll.append(4)
	ll.append(5)

	print("first linked list")
	print(ll)
	print()

	ll2 = Linked_list()
	ll2.append(1)
	ll2.append(2)
	ll2.append(4)
	ll2.append(5)

	print("second linked list")
	print(ll2)
	print()

	print("first == second is " + str(ll == ll2))
	print()

	ll.delete(3)
	print("after calling first.delete(3)")
	print(ll)
	print()
	print("first == second is " + str(ll == ll2))
	print()

	ll3 = Linked_list()
	ll3.append("I am a string")
	ll3.append(True)
	ll3.append(948737)
	ll3.append(["another String",42,False])

	print("third linked list contains different types of objects")
	print(ll3)
	print()

	ll4 = Linked_list()
	ll4.append(ll)
	ll4.append(ll2)
	ll4.append(ll3)

	print("fourth linked list contains other linked lists")
	print(ll4)
	print()

	print("get the element at each index of the third linked list and print it")
	for index in range(ll3.length):
		print(ll3.get(index))