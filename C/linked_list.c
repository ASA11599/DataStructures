struct Node {
	void * val;
	struct Node * prev;
	struct Node * next;
};

struct Linked_list {
	struct Node * dummy;
	int size;
};

struct Node * create_Node(void * v)
{
	static struct Node n;
	n.val = v;
	n.prev = &n;
	n.next = &n;
	return &n;
}

struct Linked_list * create_linked_list(void)
{
	static struct Linked_list ll;
	ll.size = 0;
	void * v;
	ll.dummy = create_Node(v);
	return &ll;
}