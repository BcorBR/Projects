#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{
    Tree* tree = createTree();

    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 17);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 6);

    printf("\n\nInsert 35");
    tree->root = insert(tree->root, 35);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 4);

    printf("\n\nInsert 14");
    tree->root = insert(tree->root, 14);

    printf("\n\nInsert 23");
    tree->root = insert(tree->root, 23);

    printf("\n\nInsert 48");
    tree->root = insert(tree->root, 48);

    printf("\n\nBuscar 14\n");
    int achou = search(tree->root, 100);
    printf("%d", achou);

    Node* node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    node = getMaxNode(tree->root);
    printf("\n\nMaior: %d", node->data);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pós-ordem\n");
    strPostorder(tree->root);

    printf("\n\ndeleteNode(4)\n");
    node = deleteNode(tree->root, 17, 'D');

    node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pós-ordem\n");
    strPostorder(tree->root);

    //Testando a nova funcao para contar subnos
    int count = countSubnodes(tree->root, 6);
    printf("\n\nQuantidade de subnós abaixo de 6 incluindo ele mesmo é de %d\n", count);

    return 0;
}
