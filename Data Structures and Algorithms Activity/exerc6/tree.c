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
        // Caso base: se o n� for nulo, retorna 0.
        return 0;
    } else {
        // Caso recursivo: o n� atual n�o � nulo, ent�o conta-se 1 (n� atual)
        // mais os n�s � esquerda e os n�s � direita.
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
}


/*
Esse c�digo abaixo implementa uma fun��o chamada countSubnodes, que recebe dois par�metros: um ponteiro para um n� (Node* node)
de uma �rvore bin�ria e um valor inteiro (int data). O objetivo da fun��o � contar todos os n�s que s�o subn�s de um determinado n� que cont�m o valor data.
*/

int countSubnodes(Node* node, int data) {
    // Verifica se o n� atual � nulo, o que significa que chegou ao fim de um ramo ou a �rvore est� vazia.
    // Nesse caso, a fun��o retorna 0, pois n�o h� n�s para contar.
    if (node == NULL) {
        return 0;
    }

    // Se o valor do n� atual for igual ao valor que estamos procurando (data),
    // a fun��o conta todos os n�s da sub�rvore a partir deste n�, chamando a fun��o countNodes.
    if (node->data == data) {
        return countNodes(node); // Conta todos os n�s da sub�rvore (n� atual + seus descendentes).
    }

    // Caso contr�rio, faz uma busca no lado esquerdo da �rvore.
    // Chama a fun��o recursivamente para o filho � esquerda.
    int leftCount = countSubnodes(node->left, data);

    // Se o valor for encontrado no lado esquerdo (leftCount maior que 0),
    // retorna o n�mero de n�s dessa sub�rvore.
    // Isso interrompe a busca, j� que n�o precisamos verificar o lado direito.
    if (leftCount > 0) {
        return leftCount;
    }

    // Se o valor n�o foi encontrado no lado esquerdo,
    // chama a fun��o recursivamente para o lado direito.
    return countSubnodes(node->right, data);
}
