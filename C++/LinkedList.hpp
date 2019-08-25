namespace ADT
{
    template <typename T>
    class LinkedList
    {

        private:
            /**
             * Nested class for Nodes
            */
            template <typename E>
            class Node
            {
                public:
                    // using a pointer for easier memory management
                    E * value;
                    Node<E> * prev;
                    Node<E> * next;
                    /**
                     * Constructor:
                     * creates a node
                    */
                    Node(const E * value)
                    {
                        this->value = value;
                        this->prev = nullptr;
                        this->next = nullptr;
                    }
                    /**
                     * Constructor:
                     * creates a node
                    */
                    Node(const E * value, Node<T> * prev, Node<T> * next)
                    {
                        this->value = value;
                        this->prev = prev;
                        this->next = next;
                    }
                    /** Constructor for the dummy node:
                    * ONLY USE TO CREATE DUMMY NODE
                    */
                    Node()
                    {
                        this->value = nullptr;
                        this->prev = this;
                        this->next = this;
                    }
                    /**
                     * Destructor:
                     * destroys the Node and its value but does not touch prev and next
                    */
                    ~Node()
                    {
                        // we can do this because this->value will always be a pointer
                        delete this->value;
                        // we do NOT want to delete prev and next as they will be used by the list
                    }
            };

        private:
            Node<T> * dummy;
            int size;

        public:
            // Constructor
            LinkedList()
            {
                this->size = 0;
                this->dummy = new Node<T>();
            }

            // Destructor
            ~LinkedList()
            {
                Node<T> * toDelete = this->dummy->next;
                Node<T> * cursor = toDelete;
                while (toDelete != this->dummy) {
                    cursor = toDelete->next;
                    delete toDelete;
                    toDelete = cursor;
                }
                delete this->dummy;
            }

            // Instance methods

            bool isEmpty();
            int getSize();
            void addLast(T item);
            void addFirst(T item);
            void add(T* item, int index);
            T getLast();
            T getFirst();
            T get(int index);
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
    int LinkedList<T>::getSize()
    {
        return this->size;
    }

    template <typename T>
    void LinkedList<T>::addLast(T item)
    {
        throw "Not implemented yet!";
    }

    template <typename T>
    void LinkedList<T>::addFirst(T item)
    {
        throw "Not implemented yet!";
    }

    template <typename T>
    T LinkedList<T>::getFirst()
    {
        throw "Not implemented yet!";
    }

    template <typename T>
    T LinkedList<T>::getLast()
    {
        throw "Not implemented yet!";
    }

    template <typename T>
    T LinkedList<T>::get(int index)
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
}