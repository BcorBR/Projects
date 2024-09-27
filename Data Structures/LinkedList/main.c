#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
    node_t *head = NULL;
    node_t *tmp;

    for (int i=0; i < 30; i++){
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }
    printlist(head);

    return 0;
}
