#include <stdlib.h>
#include <stdio.h>

#include "fila_estaticaCircular.h"
#include "listaEst.h"

int main(){
    // checar se funciona remove remover(li->entries - 1);remover head e remover se ha so um elemento   

    listaEst *li = criarListaEst(6);

    // teste 1
    printf("Deve imprimir 3 overflow\n");
    for (int i = 0; i < 4; i++)
        inserir(li, i*2, i);
    for (int i = 4; i > -1; i--)
        inserir(li, i, i);
    puts("");

    // teste 2
    printf("deve imprimir 0, 2, 4, 3, 6, 4. head = 0, tail = 4, (0, 1) (2, 2) (4, 5) (6, 4) (4, -1) (3, 3)\n");
    imprimirLista(li);
    puts("\n");

    // teste 3
    printf("deve imprimir 2, 3, 6, 4. head = 1, tail = 4. (-, -)remover(li->entries - 1); (2, 5) (-, -) (6, 4) (4, -1) (3, 3)\n");
    remover(li, 0);
    remover(li, 1);
    imprimirLista(li);
    puts("\n");

    //teste 4
    printf("printa 1 erro. 2, 6. head = 1, tail = 3. (-, -) (2, 3) (-, -) (6, -1) (-, -) (-, -)\n");
    remover(li, li->entries - 1);
    remover(li, li->entries);
    remover(li, li->entries - 2);
    imprimirLista(li);
    puts("\n");

    // teste 5
    printf("imprime 1 erro. e lista vazia");
    remover(li, 1);
    remover(li, 0);
    remover(li, 0);
    imprimirLista(li);
    puts("\n");

    // teste 6
    printf("imprime 1 valor nao esta na lista.  imprime numeros de 0 a 5. imprime 1 valor nao esta na lista e um -1\n");
    buscar(li, 5);
    for (int i = 0; i < li->tamanho; i++)
        inserir(li, i, i);
    for (int i = 0; i < li->tamanho + 1; i++)
        printf("%d ", buscar(li, i));
    puts("\n");

    //teste 7
    printf("imprime 6 e lista vazia e 0\n");
    printf("%d\n", size(li));
    clear(li);
    imprimirLista(li);
    printf("%d\n", size(li));


    return 0;
}
