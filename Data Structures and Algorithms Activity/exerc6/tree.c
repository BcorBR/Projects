#include "tree.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

int search(Node* node, int data) {
    if (node == NULL) {
        return 0;
    }
    if (node->data == data) {
        return 1;
    }
    if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

Node* getMaxNode(Node* node) {
    if (node == NULL || node->right == NULL) {
        return node;
    }
    return getMaxNode(node->right);
}

Node* getMinNode(Node* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }
    return getMinNode(node->left);
}

Node* deleteNode(Node* node, int data, char filhoSubstituto) {
    if (node == NULL) {
        return node;
    }
    if (data < node->data) {
        node->left = deleteNode(node->left, data, filhoSubstituto);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data, filhoSubstituto);
    } else {
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }
        Node* temp = getMinNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data, filhoSubstituto);
    }
    return node;
}

void strPreorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    strPreorder(node->left);
    strPreorder(node->right);
}

void strInorder(Node* node) {
    if (node == NULL) {
        return;
    }
    strInorder(node->left);
    printf("%d ", node->data);
    strInorder(node->right);
}

void strPostorder(Node* node) {
    if (node == NULL) {
        return;
    }
    strPostorder(node->left);
    strPostorder(node->right);
    printf("%d ", node->data);
}

int countNodes(Node* node) {
    if (node == NULL) {
        // Caso base: se o nó for nulo, retorna 0.
        return 0;
    } else {
        // Caso recursivo: o nó atual não é nulo, então conta-se 1 (nó atual)
        // mais os nós à esquerda e os nós à direita.
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
}


/*
Esse código abaixo implementa uma função chamada countSubnodes, que recebe dois parâmetros: um ponteiro para um nó (Node* node)
de uma árvore binária e um valor inteiro (int data). O objetivo da função é contar todos os nós que são subnós de um determinado nó que contém o valor data.
*/

int countSubnodes(Node* node, int data) {
    // Verifica se o nó atual é nulo, o que significa que chegou ao fim de um ramo ou a árvore está vazia.
    // Nesse caso, a função retorna 0, pois não há nós para contar.
    if (node == NULL) {
        return 0;
    }

    // Se o valor do nó atual for igual ao valor que estamos procurando (data),
    // a função conta todos os nós da subárvore a partir deste nó, chamando a função countNodes.
    if (node->data == data) {
        return countNodes(node); // Conta todos os nós da subárvore (nó atual + seus descendentes).
    }

    // Caso contrário, faz uma busca no lado esquerdo da árvore.
    // Chama a função recursivamente para o filho à esquerda.
    int leftCount = countSubnodes(node->left, data);

    // Se o valor for encontrado no lado esquerdo (leftCount maior que 0),
    // retorna o número de nós dessa subárvore.
    // Isso interrompe a busca, já que não precisamos verificar o lado direito.
    if (leftCount > 0) {
        return leftCount;
    }

    // Se o valor não foi encontrado no lado esquerdo,
    // chama a função recursivamente para o lado direito.
    return countSubnodes(node->right, data);
}
