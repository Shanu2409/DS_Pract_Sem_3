// adding, subtraction, multiply and Transpose of 2 matrix
// 1.c

#include <iostream>
using namespace std;

int main()
{
    int r, c, sum = 0;

    cout << "Enter row and column : " << endl;
    cin >> r >> c;

    int mt1[r][c], mt2[r][c], mt3[r][c];

    cout << endl;

    cout << "Enter elements in first matrix : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mt1[i][j];
        }

        cout << endl;
    }

    cout << endl;

    cout
        << "Enter elements in second matrix : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mt2[i][j];
        }

        cout << endl;
    }

    cout << endl;

    cout << "elements in first matrix : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mt1[i][j];
        }

        cout << endl;
    }

    cout << endl;

    cout << "elements in second matrix : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mt2[i][j];
        }

        cout << endl;
    }

    int op;

    cout << endl;

    cout << "1.add." << endl;
    cout << "2.subtract." << endl;
    cout << "3.multiply." << endl;
    cout << "4.Transpose." << endl;
    cout << endl
         << "Select your option " << endl;
    cin >> op;

    switch (op)
    {

    case 1:
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                mt3[i][j] = mt1[i][j] + mt2[i][j];
            }

            cout << endl;
        }

        cout << endl
             << "After adding" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mt3[i][j];
            }

            cout << endl;
        }

        break;

    case 2:

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                mt3[i][j] = mt1[i][j] - mt2[i][j];
            }

            cout << endl;
        }

        cout << endl
             << "After subtraction" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mt3[i][j];
            }

            cout << endl;
        }

        break;

    case 3:

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                sum = 0;
                for (int k = 0; k < r; k++)
                    sum = sum + (mt1[i][k] * mt2[k][j]);
                mt3[i][j] = sum;
            }
        }

        cout << endl
             << "After multiplication" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << mt3[i][j] << "\t";
            cout << endl;
        }

        break;

    case 4:

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mt3[i][j] = mt1[j][i];

        cout << endl
             << "After Transpose" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << mt3[i][j] << "\t";
            cout << endl;
        }

        break;
    }

    return 0;
}

/*

output:

Enter row and column :
3 3

Enter elements in first matrix :
1 2 3 4 5 6 7 8 9




Enter elements in second matrix :
1 2 3 4 5 6 7 8 9




elements in first matrix :
123
456
789

elements in second matrix :
123
456
789

1.add.
2.subtract.
3.multiply.
4.Transpose.

Select your option
3

After multiplication
30      36      42
66      81      96
102     126     150

*/