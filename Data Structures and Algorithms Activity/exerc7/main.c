#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main() {

  Tree* tree = createTree(); //cria a árvore
  
  tree->root = insert(tree->root, 61); //insere os valores na árvore
  insert(tree->root, 34);
  insert(tree->root, 67);
  insert(tree->root, 19);
  insert(tree->root, 50);
  insert(tree->root, 66);
  insert(tree->root, 94);
  insert(tree->root, 20);
  insert(tree->root, 55);
  insert(tree->root, 64);
  insert(tree->root, 70);
  insert(tree->root, 95);

  caminhos(tree->root, 0); //testa a função caminhos
}