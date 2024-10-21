#include "avlTree.h"

int main(){
    avlT *avl = createAvl(40);

    for (int i = 1; i < 11; i++)
        insert(avl, i);
    
    printTree(avl->root);


    return 0;
}