// implement the concept of bubble sort

#include <iostream>
using namespace std;

void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
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
    int arr[5] = {24, 14, -14, 5, 1};

    cout << "Before Sorting: ";
    printArray(arr, 5);
    BubbleSort(arr, 5);
    cout << "After sorting : ";
    printArray(arr, 5);

    return 0;
}