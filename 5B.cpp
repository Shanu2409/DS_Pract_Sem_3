// implement the selection sort

#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
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
    int arr[5] = {2, 5, -53, 62, 7};

    cout << "Before Sorting: ";
    printArray(arr, 5);
    selectionSort(arr, 5);
    cout << "After sorting : ";
    printArray(arr, 5);

    return 0;
}