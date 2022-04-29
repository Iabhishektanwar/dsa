#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray * a , int tSize, int uSize){
    a->totalSize = tSize;
    a->usedSize = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int));
    
}

void show(struct myArray * a){
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d", (a->ptr)[i]);
    }
    
}

void setVal(struct myArray * a){
    int n;
    for (int i = 0; i < a->usedSize; i++)
    { 
        scanf("%d", &n);
        a->ptr[i] = n;
    }
    
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 5);
    setVal(&marks);
    show(&marks);
    return 0;
}