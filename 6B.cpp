#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }

    return -1;
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
    int arr[5] = {1, 2, 7, 4, 5};

    cout << "Elements in array are: ";
    printArray(arr, 5);

    int k;
    cout << "Enter the element to search: ";
    cin >> k;

    int index = linearSearch(arr, 5, k);

    if (index == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << index << endl;

    return 0;
}
