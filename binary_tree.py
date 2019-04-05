class Binary_tree:

	class Node:
		def __init__(self,value,left=None,right=None):
			self.value = value
			self.left = left
			self.right = right

		def __repr__(self):
		  return str(self.value)

	def __init__(self):
		self.root = None

	def add(self,value):
		if self.root == None:
			self.root = Binary_tree.Node(value)
		current = self.root
		while current != None:
			if current.value == value:
				return
			elif value > current.value:
				if current.right != None:
					current = current.right
				else:
					current.right = Binary_tree.Node(value)
					return
			elif value < current.value:
				if current.left != None:
					current = current.left
				else:
					current.left = Binary_tree.Node(value)
					return

	def contains(self,value):
		current = self.root
		while current != None:
			if current.value == value:
				return True
			elif value > current.value:
				current = current.right
			elif value < current.value:
				current = current.left
		return False