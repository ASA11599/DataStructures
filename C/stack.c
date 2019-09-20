#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void * value;
    Node * under;
} Node;

typedef struct Stack {
    int size;
    Node * top;
} Stack;

Node * create_node(void * val_ptr)
{
    Node * node_ptr = (Node *) malloc(sizeof(struct Node));
    node_ptr->value = val_ptr;
    node_ptr->under = NULL;
    return node_ptr;
}

Stack * create_stack(void)
{
    Stack * stack_ptr = (Stack *) malloc(sizeof(Stack));
    stack_ptr->size = 0;
    stack_ptr->top = NULL;
    return stack_ptr;
}

void destroy_node(Node * node)
{
    free(node->value);
}

void destroy_stack(Stack * stack)
{
    Node * current = stack->top;
    while (current->under != NULL) {
        Node * temp = current;
        current = current->under;
        destroy_node(temp);
        free(temp);
    }
}

bool stack_is_empty(Stack * stack)
{
    return stack->size == 0;
}

void stack_push(Stack * stack, void * val_ptr)
{
    if (stack_is_empty(stack)) {
        stack->top = create_node(val_ptr);
        stack->size++;
    } else {
        Node * new_node = create_node(val_ptr);
        new_node->under = stack->top;
        stack->top = new_node;
        stack->size++;
    }
}

void * stack_peek(Stack * stack)
{
    if (stack_is_empty(stack)) {
        return NULL;
    } else {
        return stack->top->value;
    }
}

void * stack_pop(Stack * stack)
{
    if (stack_is_empty(stack)) {
        return NULL;
    } else {
        Node * top_node = stack->top;
        void * val = stack_peek(stack);
        stack->top = stack->top->under;
        stack->size--;
        destroy_node(top_node);
        free(top_node);
        return val;
    }
}

int main(void)
{

    Stack * s = create_stack();

    char a = 'a';
    char b = 'b';
    char c = 'c';

    stack_push(s, (void *) &a);
    stack_push(s, (void *) &b);
    stack_push(s, (void *) &c);

    while (!stack_is_empty(s)) {
        printf("%c\n", *((char *) stack_pop(s)));
    }

    destroy_stack(s);

    return 0;
}