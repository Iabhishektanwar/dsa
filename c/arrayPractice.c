#include <stdio.h>

void transversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int index, int number, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = number;
        return 1;
    }
}

int deletion(int arr[], int size, int index, int capacity)
{
    if (size <= capacity)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        return 1;
    }
    else
    {
        return -1;
    }
}

int linerarSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void deletionByElement(int arr[], int size, int element)
{
    int a = linerarSearch(arr, size, element);
    deletion(arr, size, a, 10);
}

int main()
{
    int array[] = {3, 7, 9, 10, 19, 67};
    int s = sizeof(array) / sizeof(int);
    transversal(array, s);
    insertion(array, s, 2, 6, 10);
    s += 1;
    transversal(array, s);
    deletion(array, s, 5, 10);
    s -= 1;
    transversal(array, s);

    int c = linerarSearch(array, s, 10);
    // printf("%d\n", c);

    int d = binarySearch(array, s, 10);
    // printf("%d\n", d);

    deletionByElement(array, s, 10);
    s -= 1;
    transversal(array, s);

    return 0;
}