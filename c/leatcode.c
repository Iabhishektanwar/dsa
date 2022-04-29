#include <stdio.h>

void transverse(int *a, int al)
{
    for (int i = 0; i < al; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int arraylength = sizeof(array) / sizeof(int);
    transverse(array, arraylength);
    return 0;
}