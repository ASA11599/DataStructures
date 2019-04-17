public interface List<T> {
	boolean isEmpty();
	boolean contains(T item);
	int size();
	T get(int index);
	void addLast(T item);
	void add(T item, int index);
	void remove(T item);
	void remove(int index);
}