public class ArrayStack<E> implements Stack<E> {


	private E[] elements;
	private int top;
	private static final int DEFAULT_CAPACITY = 25;
	private int capacity;


	public ArrayStack() {
		this(ArrayStack.DEFAULT_CAPACITY);
	}

	@SuppressWarnings("unchecked")
	public ArrayStack(int capacity) throws IllegalArgumentException {
		if (capacity < 0) {
			throw new IllegalArgumentException("Negative capacity!");
		}
		this.elements = (E[]) new Object[capacity];
		this.top = -1;
		this.capacity = capacity;
	}

	public boolean isEmpty() {
		return this.top == -1;
	}

	public void push(E data) throws IllegalStateException {
		if (this.top >= this.capacity-1) {
			throw new IllegalStateException("Stack is full!");
		}
		this.top++;
		this.elements[top] = data;
	}

	public E peek() throws IllegalStateException {
		if (this.isEmpty()) {
			throw new IllegalStateException("Stack is empty!");
		}
		return this.elements[this.top];
	}

	public E pop() throws IllegalStateException {
		if (this.isEmpty()) {
			throw new IllegalStateException("Stack is empty!");
		}
		this.top--;
		return this.elements[this.top+1];
	}

	public int size() {
		return this.top + 1;
	}


}