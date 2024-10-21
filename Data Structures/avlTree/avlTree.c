#include <stdlib.h>
#include <stdio.h>

#include "avlTree.h"

// returns max number
int max(int *a, int *b){
    return (*a > *b) ? *a: *b;
}

node *createNode(int val){
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL){
        printf("COuld not initialize node\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    new->data = val;
    new->heightL = 0;
    new->heightR = 0;

    return new;
}

avlT *createAvl(int val){
    avlT *avl = (avlT *)malloc(sizeof(avlT));
    avl->root = createNode(val);

    return avl;
}

void updateHeight(node *aux){
    if (aux == NULL)
        return;
    
    // config new height of aux
    if (aux->left != NULL)
        aux->heightL = max(&(aux->left->heightL), &(aux->left->heightR)) + 1;
    else
        aux->heightL = 0;
    
    if (aux->right != NULL)
        aux->heightR = max(&(aux->right->heightL), &(aux->right->heightR)) + 1;
    else
        aux->heightR = 0; 

    updateHeight(aux->parent);
}

void rotateLeft(node *aux){
    if (aux == NULL || aux->right == NULL)
        return;
    // rotate left
    if (aux->parent != NULL){
        aux->right->parent = aux->parent;
        if (aux->parent->right == aux)
            aux->parent->right = aux->right;
        else
            aux->parent->left = aux->right;
    }
    aux->parent = aux->right;
    
    if (aux->parent->left != NULL){
        aux->right = aux->parent->left;
        aux->right->parent = aux;
    }
    aux->parent->left = aux;

    // config new height of aux and ancestors
    updateHeight(aux);
}   

void rotateRight(node *aux){
    if (aux == NULL || aux->left == NULL)
        return;
    // rotate right
    if (aux->parent != NULL){
        aux->left->parent = aux->parent;
        if (aux->parent->right == aux)
            aux->parent->right = aux->left;
        else
            aux->parent->left = aux->left;
    }
    aux->parent = aux->left;

    if (aux->parent->right != NULL){
        aux->left = aux->parent->right;
        aux->left->parent = aux;
    }
    aux->parent->right = aux;

    // config new height of aux and ancestors
    updateHeight(aux);
}   


void rotateFilter(node *aux){
    if (aux == NULL)
        return;

    // right heavy, rotate left
    if (aux->heightL - aux->heightR < -1 && aux->right->heightL - aux->right->heightR <= 0)
        rotateLeft(aux);
    // left heavy, rotate right
    else if (aux->heightL - aux->heightR > 1 && aux->right->heightL - aux->right->heightR >= 0)
        rotateRight(aux);
    // right heavy, subtree left heavy. rotate left-right
    else if (aux->heightL - aux->heightR < -1){
        rotateRight(aux->right);
        rotateLeft(aux);
    }
    // left heavy, subtree right heavy. rotate right-left
    else if (aux->heightL - aux->heightR > 1){
        rotateRight(aux->left);
        rotateLeft(aux);
    }
    
    // checks for imbalances of ancestor nodes
    rotateFilter(aux->parent);

    return;
}

void insert(avlT *avl, int val){
    node *aux = avl->root;
    node *new = createNode(val);
    
    // find position to insert
    while (aux != NULL){
        
        if (val > aux->data){
            aux->heightR++;
            if (aux->right == NULL){
                aux->right = new;
                new->parent = aux;
                break;
            }
            else
                aux = aux->right;
        }

        else{
            aux->heightL++;
            if (aux->left == NULL){
                aux->left = new;
                new->parent = aux;
                break;
            }
            else
                aux = aux->left;
        }
    }

    // balance tree
    rotateFilter(aux->parent);
}

node *binSearch(avlT *avl, int val){
    node *n = (node *)malloc(sizeof(node));
    n = avl->root;
    
    while (n != NULL){
        if (val > n->data)
            n = n->right;
        else if (val < n->data)
            n = n->left;
        else
            return n;
    }

    printf("Element is not in the list\n");
    return NULL;
}

void freeSubTree(node *n){
    if (n == NULL)
        return;
    freeSubTree(n->right);
    freeSubTree(n->left);
    free(n);
}

void clearTree(avlT *avl){
    freeSubTree(avl->root);
    free(avl);
}

void printTree(node *node){
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printTree(node->left);
    printTree(node->right);
}

/*
void removeElement(avlT *avl, int val){
    node *n = (node *)malloc(sizeof(node));
    n = binSearch(avl, val);
    if (n == NULL){
        printf("Element not found\n");
        return;
    }

    node *aux = (node *)malloc(sizeof(node));
    if (n->right != NULL){
        aux = n->right;
        
        if (aux->left != NULL){
            while (aux->left != NULL)
                aux = aux->left;
            
            if (aux->right != NULL){
                aux->parent->left = aux->right;
                aux->right->parent = aux->parent;
            }

            if (n->parent != NULL){
                if (n->parent->right == n){
                    n->parent->right = aux;
                    aux->parent = n->parent;
                }
                else if (n->parent->left == n){
                    n->parent->left = aux;
                    aux->parent = n->parent;
                }
            }
            
            if (n->left != NULL){
                n->left->parent = aux;
                aux->left = n->left;
            }
            n->right->parent = aux;
            aux->right = n->right;

            free(n);
        }
        else{
            // n->right != NULL
            // n->right->left == NULL
            n->parent = aux->parent;
            //
        }
    }

    else if(n->left != NULL){
        aux = n->left;


    }


}
*/

