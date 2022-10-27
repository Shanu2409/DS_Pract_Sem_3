#include <iostream>
using namespace std;

class Stack
{
public:
    char *arr;
    int top;
    int size;
    Stack(int n)
    {
        this->size = n;
        arr = new char[size];
        top = -1;
    }

    void push(char c)
    {
        if (top == size)
        {
            cout << "stack overflow !!!";
            return;
        }
        top++;
        arr[top] = c;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int temp = arr[top];
        top--;
        return temp;
    }

    void display()
    {
        int cnt = top;

        while (cnt >= 0)
        {
            cout << arr[cnt] << " ";
            cnt--;
        }
        cout << endl;
    }
};

int main()
{

    Stack s(5);
    s.push(2);
    s.push(5);
    s.push(25);

    s.display();

    return 0;
}