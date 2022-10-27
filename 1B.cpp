// read the two arrays from the user and merge them and display the elements in sorted order.

#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    cout << "Enter the size of the second array: ";
    cin >> n2;
    int *a = new int[n1];
    int *b = new int[n2];
    int *c = new int[n1 + n2];

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n1; i++)
    {
        c[i] = a[i];
    }

    for (int i = 0; i < n2; i++)
    {
        c[n1 + i] = b[i];
    }

    for (int i = 0; i < n1 + n2; i++)
    {
        for (int j = i + 1; j < n1 + n2; j++)
        {
            if (c[i] > c[j])
            {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    cout << "The sorted array is: ";
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}

/*

output :

Enter the size of the first array: 3
Enter the size of the second array: 4
Enter the elements of the first array: 3 2 1
Enter the elements of the second array: 7 6 5 4
The sorted array is: 1 2 3 4 5 6 7



*/