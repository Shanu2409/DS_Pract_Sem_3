// write a porgram to store the elements in a one dimensional array and perform the operations like searchin,sorting, and reversing the elements.

#include <iostream>
using namespace std;

int search(int *a, int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

void sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void reverse(int *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

int main()
{
    int n, choice;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "1.Searching" << endl;
    cout << "2.Sorting" << endl;
    cout << "3.Reversing" << endl;
    cout << "Enter your choice : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        int key, ans;
        cout << "Enter the element to be searched : ";
        cin >> key;
        ans = search(arr, n, key);
        if (ans == -1)
            cout << "Element not found" << endl;
        else
            cout << "Element found at index " << ans << endl;
        break;

    case 2:
        sort(arr, n);
        cout << "Sorted array is : ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        break;

    case 3:
        reverse(arr, n);
        cout << "Reversed array is : ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}

/*

Output 1:

Enter the number of elements in the array : 6
Enter the elements in the array
3 236 4 13 41 6
1.Searching
2.Sorting
3.Reversing
Enter your choice : 2
Sorted array is : 3 4 6 13 41 236

---------------------------------------------------------------

Output 2:

Enter the number of elements in the array : 4
Enter the elements in the array
1 51 62 6
1.Searching
2.Sorting
3.Reversing
Enter your choice : 1
Enter the element to be searched : 62
Element found at index 2

---------------------------------------------------------------

output 3:

Enter the number of elements in the array : 5
Enter the elements in the array
52 63 12 63 8
1.Searching
2.Sorting
3.Reversing
Enter your choice : 3
Reversed array is : 8 63 12 63 52

*/