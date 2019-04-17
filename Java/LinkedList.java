import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedList<E> implements List<E>,Iterable<E> {


	// INSTANCE VARIABLES
	private int size;
	private final Node<E> dummy; //final?

	// NODE NESTED CLASS
	private static class Node<R> {
		private Node<R> next;
		private Node<R> prev;
		private R value;

		public Node(R value) {
			this.value = value;
			this.next = this.prev = this;
		}
	}

	// ITERATOR INNER CLASS
	private class LinkedListIterator implements Iterator<E> {
		private Node<E> current;
		public LinkedListIterator() {
			this.current = LinkedList.this.dummy;
		}
		public E next() {
			this.current = this.current.next;
			return this.current.value;
		}
		public boolean hasNext() {
			return this.current.next.value != null;
		}
	}

	public LinkedList() {
		this.dummy = new Node<E>(null);
		this.size = 0;
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public int size() {
		return this.size;
	}

	public boolean contains(E item) {
		Node<E> current = this.dummy.next;
		while (current.value != null) {
			if (current.value.equals(item)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}

	public E get(int index) throws IndexOutOfBoundsException {
		if ((index < 0) || (index >= this.size)) {
			throw new IndexOutOfBoundsException();
		}
		int currentIndex = 0;
		Node<E> currentNode = this.dummy.next;
		while (currentIndex < index) {
			currentNode = currentNode.next;
			currentIndex++;
		}
		return currentNode.value;
	}

	public void addLast(E item) {
		Node<E> newNode = new Node<E>(item);
		newNode.prev = this.dummy.prev;
		newNode.next = this.dummy;
		newNode.prev.next = newNode;
		this.dummy.prev = newNode;
		this.size++;
	}

	public void add(E item, int index) throws IndexOutOfBoundsException {
		if ((index < 0) || (index > this.size)) {
			throw new IndexOutOfBoundsException();
		}
		/*if (index == this.size) {
			this.addLast(item);
		}*/
		Node<E> newNode = new Node<E>(item);
		int currentIndex = 0;
		Node<E> currentNode = this.dummy.next;
		while (currentIndex < index-1) {
			currentNode = currentNode.next;
			currentIndex++;
		}
		newNode.prev = currentNode;
		newNode.next = currentNode.next;
		newNode.next.prev = newNode;
		currentNode.next = newNode;
		this.size++;
	}

	public void remove(int index) throws IndexOutOfBoundsException {
		if ((index < 0) || (index >= this.size)) {
			throw new IndexOutOfBoundsException();
		}
		int currentIndex = 0;
		Node<E> currentNode = this.dummy.next;
		while (currentIndex < index) {
			currentNode = currentNode.next;
			currentIndex++;
		}
		currentNode.prev.next = currentNode.next;
		currentNode.next.prev = currentNode.prev;
		this.size--;
	}

	public void remove(E item) throws NoSuchElementException {
		if (!this.contains(item)) {
			throw new NoSuchElementException();
		}
		Node<E> current = this.dummy.next;
		while (!current.value.equals(item)) {
			current = current.next;
		}
		current.prev.next = current.next;
		current.next.prev = current.prev;
		this.size--;
	}

	public Iterator<E> iterator() {
		return new LinkedListIterator();
	}

	public String toString() {
		StringBuffer s = new StringBuffer("[");
		Node<E> current = this.dummy.next;
		while (current.value != null) {
			s.append(current.value.toString() + (current.next.value != null ? (",") : ("")));
			current = current.next;
		}
		s.append("]");
		return s.toString();
	}


}