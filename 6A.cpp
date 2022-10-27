#include <iostream>
using namespace std;

int binSearch(int *arr, int s, int e, int k)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return mid;

    if (k > arr[mid])
        return binSearch(arr, mid + 1, e, k);
    else
        return binSearch(arr, s, mid, k);
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
    int arr[8] = {1, 2, 3, 4, 5, 10, 15, 20};

    cout << "Elements in array are: ";
    printArray(arr, 8);

    int k;
    cout << "Enter the element to search: ";
    cin >> k;

    int index = binSearch(arr, 0, 7, k);

    if (index == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << index << endl;

    return 0;
}
