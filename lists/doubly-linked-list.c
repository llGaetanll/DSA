#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list {
    struct node* start;
    struct node* end;
} List;

List* new_list() {
    List* list = malloc(sizeof(List*));
    list->start = NULL;
    list->end = NULL;

    return list;
}

Node* new_node(int data) {
    Node* new_node = malloc(sizeof(Node*));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

// push to beggining of list. O(1)
void prepend(List *const list, int data) {
    // create a new node & add data
    Node* node = new_node(data);

    // link new node
    node->next = list->start;
    if (list->start)
        list->start->prev = node;

    // set end node
    if (!list->end)
        list->end = node;

    // update the start node
    list->start = node;
}

// push to end of list. O(1)
void append(List *const list, int data) {
    // create a new node & add data
    Node* node = new_node(data);

    // link the new node
    node->prev = list->end;
    if (list->end)
        list->end->next = node;

    // set start node
    if (!list->start)
        list->start = node;

    // update the end node
    list->end = node;
}

// remove a node given its index, 0 being the first node after the list
// returns -1 if error, 0 otherwise. O(i)
int rem_i(List *const list, int index) {
    int i = 1;

    // get to index - 1 
    Node* current = list->start;
    while (current->next && index > i++) current = current->next;

    // if the next does not exist
    if (i-1 != index)
        return -1;

    // remove the next node
    Node* del = current->next;
    current->next = del->next;
    free(del);

    return 0;
}

// remove the first node of a given value. returns -1 if error, 0 otherwise. O(n)?
int rem_v(List *const list, int value) {

    // get to one node before
    Node* current = list->start;
    while (current->next && current->next->data != value) current = current->next;

    // if we can't find the node from the value
    if (current->data != value)
        return -1;

    // remove the next node
    Node* del = current->next;
    current->next = del->next;
    free(del);

    return 0;
}

void print(List *const list) {
    Node* node = list->start;

    // only one node
    if (node && node == list->end) {
        printf("%d", node->data);
        node = node->next;
    }
    
    while (node && node->next) {
        printf("%d<->", node->data);
        node = node->next;
    }

    // last node
    if (node)
        printf("%d", node->data);

    endl;
}

int main() {
    List* my_list = new_list();
    print(my_list);

    append(my_list, 0);
    print(my_list);

    prepend(my_list, -1);
    print(my_list);

    for (int i = 1; i < 10; i++) append(my_list, i);

    print(my_list);
}
