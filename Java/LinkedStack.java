public class LinkedStack<E> implements Stack<E> {


    private static class Node<T> {

        private T value;
        private Node<T> under;

        public Node(T value) {
            this.value = value;
            this.under = null;
        }

    }


    private Node<E> top;
    private int size;


    public LinkedStack() {
        this.top = null;
        this.size = 0;
    }


    public void push(E item) {
        Node<E> temp = this.top;
        this.top = new Node<E>(item);
        this.top.under = temp;
        this.size++;
    }


    public E pop() throws IllegalStateException {
        if (this.isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        Node<E> temp = this.top;
        this.top = this.top.under;
        this.size--;
        return temp.value;
    }


    public E peek() throws IllegalStateException {
        if (this.isEmpty()) {
            throw new IllegalStateException("Stack is empty!");
        }
        return this.top.value;
    }


    public boolean isEmpty() {
        return this.size == 0;
    }


}