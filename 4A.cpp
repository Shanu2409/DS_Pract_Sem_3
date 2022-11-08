#include <iostream>
using namespace std;

class q
{
public:
    int size;
    int front, rear;
    int *arr;

    q(int d)
    {
        this->size = d;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int d)
    {
        if (rear == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        else if (rear == -1)
            front = rear = 0;
        else
            rear++;
        arr[rear] = d;
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        int ans = arr[front];

        if (front == rear)
            front = rear = -1;

        else
            front++;

        return ans;
    }

    void display()
    {
        if (rear == -1)
            return;

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    q n(2);
    n.enqueue(5);
    n.enqueue(2);
    n.enqueue(5);
    // cout << n.dequeue();
    // cout << n.dequeue();
    n.display();

    return 0;
}