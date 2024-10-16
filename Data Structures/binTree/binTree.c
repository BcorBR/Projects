#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *right;
    struct Node *left;
} node;

typedef struct tree{
    struct Node *root;
} tree;

void insertNode(int val, struct tree *tr){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = val;
    
    // find place to insert node
    if (tr->root == NULL){
        tr->root = newNode;
        return;
    }
    node *auxNode = tr->root;

    while (1){
        if (newNode->value >= auxNode->value){
            if (auxNode->right != NULL)
                auxNode = auxNode->right;
            else{
                auxNode->right = newNode;
                break;
            }
        }
        else{
            if (auxNode->left != NULL)
                auxNode = auxNode->left;
            else{
                auxNode->left = newNode;
                break;
            }
        }
    }
}


bool deleteNode(int val, node *n){
    // 0 if parent came from left, 1 if from right
    int side = 0;

    node *auxNode = n;
    node *prevNode = (node *)malloc(sizeof(node));
    while (auxNode != NULL){
        if (val > auxNode->value){
            prevNode = auxNode;
            auxNode = auxNode->right;
            side = 1;
        }
        else if (val < auxNode->value){
            prevNode = auxNode;
            auxNode = auxNode->left;
            side = 0;
        }

        else{
            if (side){
                prevNode->right = auxNode->left;
                node *saveNode = auxNode->right;
                auxNode = auxNode->left;
                while (auxNode->right != NULL)
                    auxNode = auxNode->right;
                auxNode->right = saveNode;
            }
            else{
                prevNode->left = auxNode->right;
                node *saveNode = auxNode->left;
                auxNode = auxNode->right;
                while (auxNode->left != NULL)
                    auxNode = auxNode->left;
                auxNode->left = saveNode;
            }
            return true;
        }
             
    }
    return false;
}


bool search(int val, node *n){
    node *auxNode = (node *)malloc(sizeof(node));
    auxNode = n;
    while (auxNode != NULL){
        if (auxNode->value > val)
            auxNode = auxNode->right;
        else if (auxNode->value < val)
            auxNode = auxNode->left;
        else
            return true; 
    }
    return false;
}

int maxTree(node *n){
    node *auxNode = n;
    while (auxNode->right != NULL)
        auxNode = auxNode->right;
    return auxNode->value;
}

int minTree(node *n){
    node *auxNode = n;
    while (auxNode->left != NULL)
        auxNode = auxNode->left;
    return auxNode->value;
}

void printTree(node *node){
    if (node == NULL)
        return;

    printf("%d ", node->value);
    printTree(node->left);
    printTree(node->right);
}

int main(){
    int arr[7] = {6, 2, 1, 3, 8, 12, 11};
    tree tr;

    printTree(tr.root);
    for (int i = 0; i < 7; i++)
        insertNode(arr[i], &tr);

    printTree(tr.root);
    puts("");
    deleteNode(6, tr.root);
    printTree(tr.root);

    
}

