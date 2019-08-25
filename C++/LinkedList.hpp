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
                     * creates a node from a value pointer
                    */
                    Node(const E * value)
                    {
                        Node(value, nullptr, nullptr);
                    }
                    /**
                     * Constructor:
                     * creates a node from a value
                    */
                    Node(const E value)
                    {
                        Node(value, nullptr, nullptr);
                    }
                    /**
                     * Constructor:
                     * creates a node from a value pointer
                    */
                    Node(const E * value, Node<T> * prev, Node<T> * next)
                    {
                        this->value = value;
                        this->prev = prev;
                        this->next = next;
                    }
                    /**
                     * Constructor:
                     * creates a node form a value
                    */
                    Node(const E value, Node<T> * prev, Node<T> * next)
                    {
                        this->value = new E(value);
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
            void addLast(T * itemptr);
            void addLast(T itemptr);
            void addFirst(T * itemptr);
            void addFirst(T item);
            void add(T * itemptr, int index);
            void add(T item, int index);
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
    void LinkedList<T>::addLast(T * itemptr)
    {
        Node<T> * oldLast = this->dummy->prev;
        this->dummy->prev = new Node<T>(itemptr, oldLast, this->dummy);
        oldLast->next = this->dummy->prev;
        this->size++;
    }

    template <typename T>
    void LinkedList<T>::addLast(T item)
    {
        addLast(new T(item));
    }

    template <typename T>
    void LinkedList<T>::addFirst(T * itemptr)
    {
        Node<T> * oldFirst = this->dummy->next;
        this->dummy->next = new Node<T>(itemptr, this->dummy, currentFirst);
        oldFirst->prev = this->dummy->next;
        this->size++;
    }

    template <typename T>
    void LinkedList<T>::addFirst(T item)
    {
        addFirst(new T(item));
    }

    template <typename T>
    void LinkedList<T>::add(T * itemptr, int index)
    {
        // TODO: throw an actual exception
        if (index >= this->getSize()) throw "Out of bounds!";
        else {
            Node<T> * current = this->dummy;
            for (int i = 0 ; i < index ; i++) {
                current = current->next;
            }
            current->next = new Node<T>(itempr, current, current->next);
            current->next->next->prev = current->next;
            this->size++;
        }
    }

    template <typename T>
    void LinkedList<T>::add(T item, int index)
    {
        add(new T(item), index);
    }

    template <typename T>
    T LinkedList<T>::getFirst()
    {
        // TODO: throw an actual exception
        if (this->getSize() == 0) throw "List is empty!";
        else {
            return *(this->dummy->next->value);
        }
    }

    template <typename T>
    T LinkedList<T>::getLast()
    {
        // TODO: throw an actual exception
        if (this->getSize() == 0) throw "List is empty!";
        else {
            return *(this->dummy->prev->value);
        }
    }

    template <typename T>
    T LinkedList<T>::get(int index)
    {
        // TODO: throw an actual exception
        if (index >= this->getSize()) throw "Out of bounds!";
        else {
            Node<T> * current = this->dummy->next;
            for (int i = 0 ; i < index ; i++) {
                current = current->next;
            }
            return *(current->value);
        }
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