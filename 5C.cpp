// implement the insertion sort

#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j--];
        }

        arr[j + 1] = k;
    }
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
    int arr[5] = {-1, 5, -36, 2, 7};

    cout << "Before Sorting: ";
    printArray(arr, 5);
    insertionSort(arr, 5);
    cout << "After sorting : ";
    printArray(arr, 5);

    return 0;
}