#include <stdio.h>
#include <stdlib.h>

int main(){
    int capacity;

    scanf("%d", &capacity);

    int *set = (int *)malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; i++)
        set[i] = -1;
    

    int ElementAmount;
    scanf("%d", &ElementAmount); //amount of elements to be read

    int curElement;
    float testElement;
    int pos;
    for (ElementAmount; ElementAmount > 0; ElementAmount--){
        scanf("%f", &testElement);

        // tests if element is valid
        if (testElement < 0 || testElement != (int)testElement)
            continue;
        
        // if it's valid
        curElement = (int)testElement;
        
        pos = curElement % capacity;
        
        // look for right position
        while (set[pos] != -1 && pos < capacity){ // se der errado, colocar -1 em vez de NULL
            pos++;
            
            // if number already in set, go to next number
            if (set[pos] == curElement)
                break;
        }
        // if number already in set, go to next number
        if (set[pos] == curElement)
            continue;
        
        // if we have passed the set capacity
        if (pos == capacity)
            continue;

        set[pos] = curElement;
    }


    // now, let's remove the asked elements
    int removeAmount;
    scanf("%d", &removeAmount);

    for (removeAmount; removeAmount > 0; removeAmount--){
        scanf("%f", &testElement);

        // tests if element is valid
        if (testElement < 0 || testElement != (int)testElement)
            continue;
        
        // if it's valid
        curElement = (int)testElement;

        pos = curElement % capacity;

        while (pos < capacity){
            // we found our element
            if (set[pos] == curElement){
                set[pos] = -1;
                break;
            }
            pos++;
        }
    }



    // search elements
    int searchAmount;
    scanf("%d", &searchAmount);

    for (searchAmount; searchAmount > 0; searchAmount--){
        scanf("%f", &testElement);

        // tests if element is valid
        if (testElement < 0 || testElement != (int)testElement){
            printf("-1 ");
            continue;
        }
        
        // if it's valid
        curElement = (int)testElement;
        
        pos = curElement % capacity;

        while (pos < capacity){
            if (set[pos] == curElement){
                printf("%d ", pos);     
                break;
            }       
            pos++;
        }

        // might have no space if last element?????????????
        if (pos == capacity){
            printf("-1 ");
        }
    }

    return 0;
}