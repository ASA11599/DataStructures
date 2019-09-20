#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void * data;
    Node * next;
} Node;

typedef struct {
    int size;
    Node * head;
} Linked_list;

Node * create_node(void * data)
{
    Node * n = (Node *) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

Linked_list * create_linked_list(void)
{
    Linked_list * ll = (Linked_list *) malloc(sizeof(Linked_list));
    ll->size = 0;
    return ll;
}

void destroy_node(Node * node)
{
    free(node->data);
}

void destroy_ll(Linked_list * ll)
{
    Node * current = ll->head;
    while (current->next != NULL) {
        Node * temp = current;
        current = current->next;
        destroy_node(temp);
        free(temp);
    }
}

void ll_append(Linked_list * ll, void * item)
{
    if (ll->head == NULL) {
        ll->head = create_node(item);
        ll->size++;
        return;
    }
    Node * current = ll->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(item);
    ll->size++;
}

void * ll_get(Linked_list * ll, int index)
{
    if (ll->size <= index) {
        void * null_ptr;
        return null_ptr;
    }
    Node * current = ll->head;
    for (int i = 0 ; i < index ; i++) {
        current = current->next;
    }
    return current->data;
}

int main(void) {

    char a = 'a';
    char b = 'b';
    char c = 'c';

    Linked_list * ll = create_linked_list();

    ll_append(ll, (void *) &a);
    ll_append(ll, (void *) &b);
    ll_append(ll, (void *) &c);

    for (int i = 0 ; i < ll->size ; i++) {
        printf("%c\n", *((char *) ll_get(ll, i)));
    }

    return 0;
}