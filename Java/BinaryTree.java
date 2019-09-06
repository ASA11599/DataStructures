public class BinaryTree<E extends Comparable<E>> {


    // INSTANCE VARIABLES
    private Node<E> root;
    private int size;

    // NODE NESTED CLASS
    private static class Node<T> {
        private T value;
        private Node<T> left;
        private Node<T> right;
        public Node(T value) {
            this.value = value;
        }
    }

    public BinaryTree() {
        this.root = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return (this.root == null) && (this.size() == 0);
    }

    public int size() {
        return this.size;
    }

    public void add(E item) {
        if (this.isEmpty()) {
            this.root = new Node<E>(item);
        } else {
            this.add(item,this.root);
        }
        this.size++;
    }

    private void add(E item, Node<E> start) {
        int result = item.compareTo(start.value);
        if (result == 0) {
            return;
        } else if (result > 0) {
            if (start.right == null) {
                start.right = new Node<E>(item);
            } else {
                this.add(item, start.right);
            }
        } else {
            if (start.left == null) {
                start.left = new Node<E>(item);
            } else {
                this.add(item, start.left);
            }
        }
    }

    public boolean contains(E item) {
        return this.contains(item, this.root);
    }

    private boolean contains(E item, Node<E> start) {
        if (start == null) {
            return false;
        }
        int result = item.compareTo(start.value);
        if (result == 0) {
            return true;
        } else if (result > 0) {
            return this.contains(item, start.right);
        } else {
            return this.contains(item, start.left);
        }
    }

    public void printInOrder() {
        this.printInOrder(this.root);
    }

    private void printInOrder(Node<E> start) {
        if (start == null) {
            return;
        }
        this.printInOrder(start.left);
        System.out.println(start.value);
        this.printInOrder(start.right);
    }

    public void printPreOrder() {
        this.printPreOrder(this.root);
    }

    private void printPreOrder(Node<E> start) {
        if (start == null) {
            return;
        }
        System.out.println(start.value);
        this.printPreOrder(start.left);
        this.printPreOrder(start.right);
    }

    public void printPostOrder() {
        this.printPostOrder(this.root);
    }

    private void printPostOrder(Node<E> start) {
        if (start == null) {
            return;
        }
        this.printPostOrder(start.left);
        this.printPostOrder(start.right);
        System.out.println(start.value);
    }


}