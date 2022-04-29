#include <stdio.h>

void transversal(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int s, int index, int number, int capacity)
{
    if (s >= capacity)
    {
        printf("%s\n", "Array is already full.");
    }
    else
    {
        for (int i = s - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = number;
        s += 1;
        printf("%s", "Array successfully updated.\n");
    }
    return s;
}

int deletion(int arr[], int s, int index)
{
    for (int i = index; i < s; i++)
    {
        arr[i] = arr[i + 1];
    }
    s -= 1;
    return s;
}

int linearSearch(int arr[], int s, int number)
{
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == number)
        {
            printf("%s%d\n", "Number found at index ", i);
            return 1;
        }
    }
    printf("%s\n", "Number not found");
    return -1;
}

int binarySearch(int arr[], int s, int number)
{
    int low = 0;
    int high = s - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == number)
        {
            printf("%s%d\n", "Number found at index ", mid);
            return 1;
        }
        if (arr[mid] > number)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    printf("%s\n", "Number not found");
    return -1;
}

int main()
{

    int array[] = {1, 5, 7, 9, 13, 18};
    int size = sizeof(array) / sizeof(int);
    transversal(array, size);
    // int a = insertion(array, size, 0, 6, 10);
    // printf("%d\n", a);
    // transversal(array, a);
    // int b = insertion(array, a, 0, 6, 6);
    // printf("%d\n", b);
    // int c = deletion(array, a, 4);
    // printf("%d\n", c);
    // transversal(array, c);
    linearSearch(array, size, 1);
    binarySearch(array, size, 1);
    return 0;
}