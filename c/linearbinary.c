#include <stdio.h>

int lineraSearch(int arr[], int size, int elementToBeFound)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elementToBeFound)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int elementToBeFound)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == elementToBeFound)
        {
            return mid;
        }
        if (arr[mid] < elementToBeFound)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    // int array[] = {3, 5, 6, 2, 4, 8};
    // int s = sizeof(array) / sizeof(int);
    // int element = 1;
    // printf("%d\n", lineraSearch(array, s, element));

    int array1[] = {2, 4, 55, 655, 987, 1000, 4688, 8777};
    int s = sizeof(array1) / sizeof(int);
    int element = 8777;
    printf("%d\n", binarySearch(array1, s, element));

    return 0;
}