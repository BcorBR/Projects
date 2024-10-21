#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    
    int data;
    int heightL;
    int heightR;
} node;

typedef struct{
    node *root;
} avlT;

// returns max number
int max(int *a, int *b);

node *createNode(int val);

avlT *createAvl(int val);

void updateHeight(node *aux);

void rotateLeft(node *aux);

void rotateRight(node *aux);

void rotateFilter(node *aux);

void insert(avlT *avl, int val);

node *binSearch(avlT *avl, int val);

void freeSubTree(node *n);

void clearTree(avlT *avl);

void printTree(node *n);

#endif //AVLTREE_H