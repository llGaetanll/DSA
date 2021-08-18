#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

typedef struct vertex {
    int value;
    struct edge** edges;
    unsigned int edge_count;
} Vertex;

typedef struct edge {
    int weight;
    Vertex* to;
    Vertex* from;
} Edge;

void print() {
}

int main() {
}
