template <typename T>
class LinkedList
{

    private:
        // Nested class for nodes
        template <typename E>
        class Node
        {
            public:
                E * value;
                Node<E> * prev;
                Node<E> * next;
                // Constructor
                Node(const E * value) {
                    this->value = value;
                    this->prev = nullptr;
                    this->next = nullptr;
                }
                // Constructor for the dummy node
                // ONLY USE TO CREATE DUMMY NODE
                Node() {
                    this->value = nullptr;
                    this->prev = this;
                    this->next = this;
                }
        };

    private:
        Node<T> * dummy;
        int size;

    public:
        // Constructor
        LinkedList() {
            this->size = 0;
            this->dummy = new Node<T>();
        }

        // Instance methods
        bool isEmpty();
        int size();
        void addLast(T * item);
        void addFirst(T * item);
        void add(T* item, int index);
        T * getLast();
        T * getFirst();
        T * get(int index);
        void removeLast();
        void removeFirst();
        void remove(int index);


};

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return this->size == 0;
}

template <typename T>
int LinkedList<T>::size()
{
    return this->size;
}

template <typename T>
void LinkedList<T>::addLast(T * item)
{
    throw "Not implemented yet!";
}

template <typename T>
void LinkedList<T>::addFirst(T * item)
{
    throw "Not implemented yet!";
}

template <typename T>
T * LinkedList<T>::getFirst()
{
    throw "Not implemented yet!";
}

template <typename T>
T * LinkedList<T>::getLast()
{
    throw "Not implemented yet!";
}

template <typename T>
T * LinkedList<T>::get(int index)
{
    throw "Not implemented yet!";
}

template <typename T>
void LinkedList<T>::removeFirst()
{
    throw "Not implemented yet!";
}

template <typename T>
void LinkedList<T>::removeLast()
{
    throw "Not implemented yet!";
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    throw "Not implemented yet!";
}