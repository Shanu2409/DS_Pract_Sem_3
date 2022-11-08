#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];

    mainArrayIndex = mid + 1;

    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    int i1 = 0;
    int i2 = 0;
    mainArrayIndex = s;

    while (i1 < len1 && i2 < len2)
    {
        if (first[i1] < second[i2])
            arr[mainArrayIndex++] = first[i1++];
        else
            arr[mainArrayIndex++] = second[i2++];
    }

    while (i1 < len1)
        arr[mainArrayIndex++] = first[i1++];
    while (i2 < len2)
        arr[mainArrayIndex++] = second[i2++];
}

void mergeSort(int *arr, int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[15] = {5, 4, 3, 2, 1};

    cout << "Before Sorting: ";
    printArray(arr, 5);
    mergeSort(arr, 0, 5 - 1);
    cout << "After sorting : ";
    printArray(arr, 5);
    return 0;
}