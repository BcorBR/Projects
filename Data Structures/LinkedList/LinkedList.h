#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int value;
    struct node *next;
} node_t;

void printlist(node_t *head);
node_t  *create_new_node(int value);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);

#endif //LINKEDLIST_H