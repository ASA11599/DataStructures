#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void * data;
    struct Node * next;
} Node;

typedef struct Queue {
    int size;
    Node * front;
    Node * back;
} Queue;

Node * create_node(void * item)
{
    Node * node_ptr = (Node *) malloc(sizeof(Node));
    node_ptr->data = item;
    node_ptr->next = NULL;
    return node_ptr;
}

Queue * create_queue(void)
{
    Queue * queue_ptr = (Queue *) malloc(sizeof(Queue));
    queue_ptr->size = 0;
    queue_ptr->front = queue_ptr->back = NULL;
    return queue_ptr;
}

bool queue_is_empty(Queue * queue)
{
    return queue->size == 0;
}

void queue_enqueue(Queue * queue, void * item)
{
    if (queue_is_empty(queue)) {
        queue->front = queue->back = create_node(item);
        queue->size++;
    } else {
        Node * new_node = create_node(item);
        queue->back->next = new_node;
        queue->back = new_node;
        queue->size++;
    }
}

void * queue_dequeue(Queue * queue)
{
    if (queue_is_empty(queue)) {
        return NULL;
    } else {
        void * res = queue->front->data;
        queue->front = queue->front->next;
        queue->back = queue->front == NULL ? NULL : queue->back;
        queue->size--;
        return res;
    }
}

int main(void)
{
    Queue * q = create_queue();

    char a = 'a';
    char b = 'b';
    char c = 'c';

    queue_enqueue(q, (void *) &a);
    queue_enqueue(q, (void *) &b);
    queue_enqueue(q, (void *) &c);

    while (!queue_is_empty(q)) {
        printf("%c\n", *((char *) queue_dequeue(q)));
    }
}