#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    stack *s = criar_stack();

    for (int i = 0; i < 11; i++){
        push(s, i);
    };

    printStack(s);

    return 0;
}
