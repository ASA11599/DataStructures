public class ArrayQueue<E> implements Queue<E> {

	private E[] data;
	private int front;
	private int rear;
	private int size;
	private static final int DEFAULT_CAPACITY = 25;

	public ArrayQueue() {
		this(ArrayQueue.DEFAULT_CAPACITY);
	}

	@SuppressWarnings("unchecked")
	public ArrayQueue(int capacity) {
		this.data = (E[]) new Object[capacity];
		this.front = 0;
		this.rear = -1;
		this.size = 0;
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public E dequeue() throws IllegalStateException {
		if (this.isEmpty()) {
			throw new IllegalStateException("Queue is empty!");
		}
		E tmp = this.data[front];
		this.front = (this.front + 1) % this.data.length;
		this.size--;
		return tmp;
	}

	public void enqueue(E item) throws IllegalStateException {
		if (this.size >= this.data.length) {
			throw new IllegalStateException("Queue is full!");
		}
		this.data[(this.rear + 1) % this.data.length] = item;
		this.rear = (this.rear + 1) % this.data.length;
		this.size++;
	}

	public static void main(String[] args) {
		ArrayQueue<Integer> aq = new ArrayQueue<Integer>();
		for (int i = 0 ; i < 25 ; i++) {
			aq.enqueue(new Integer(i+1));
		}
		for (int i = 0 ; i < 16 ; i++) {
			aq.dequeue();
		}
		for (int i = 26 ; i < 32 ; i++) {
			aq.enqueue(new Integer(i));
		}
		aq.dequeue();
		aq.enqueue(99);
		while (!aq.isEmpty()) {
			System.out.println(aq.dequeue());
		}
		
	}

}