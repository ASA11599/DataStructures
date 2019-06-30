#include <stdio.h>
#include <stdlib.h>

struct Node {
    void * data;
    struct Node * next;
};

struct Linked_list {
    int size;
    struct Node * head;
};

struct Node * create_node(void * data)
{
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    return n;
}

struct Linked_list * create_linked_list(void)
{
    struct Linked_list * ll = (struct Linked_list *) malloc(sizeof(struct Linked_list));
    ll->size = 0;
    return ll;
}

void ll_append(struct Linked_list * ll, void * item)
{
    if (ll->head == NULL) {
        ll->head = create_node(item);
        ll->size++;
        return;
    }
    struct Node * current = ll->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(item);
    ll->size++;
}

void * ll_get(struct Linked_list * ll, int index)
{
    if (ll->size <= index) {
        void * null_ptr;
        return null_ptr;
    }
    struct Node * current = ll->head;
    for (int i = 0 ; i < index ; i++) {
        current = current->next;
    }
    return current->data;
}

int main(void) {

    char a = 'a';
    char b = 'b';
    char c = 'c';

    struct Linked_list * ll = create_linked_list();

    ll_append(ll, (void *) &a);
    ll_append(ll, (void *) &b);
    ll_append(ll, (void *) &c);

    for (int i = 0 ; i < ll->size ; i++) {
        printf("%c\n", *((char *) ll_get(ll, i)));
    }

    return 0;
}