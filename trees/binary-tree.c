#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node* root;
} Tree;

Tree* new_tree() {
    Tree* tree = malloc(sizeof(Tree*));
    tree->root = NULL;

    return tree;
}

void add_node(Tree* tree, int data) {

}

void rem_node(Tree* tree, int value) {

}

void reverse(Tree* tree) {

}

Node** preorder(Tree* tree) {

}

Node** inorder(Tree* tree) {

}

Node** postorder(Tree* tree) {

}

int main() {
    return 0;
}
