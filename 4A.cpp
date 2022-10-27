#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int n)
    {
        this->size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int n)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
            cout << "overflow";

        else if (front == -1)
            front = rear = 0;

        else if (rear == size - 1 && front != 0)
            rear = 0;

        else
            rear++;

        arr[rear] = n;
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "underflow" << endl;
            return -1;
        }
        int ans = arr[front];
        // arr[front] = -1;

        if (front == rear)
            front = rear = -1 % size;

        else if (front == size - 1)
            front = 0;

        else
            front++;

        return ans;
    }

    void display()
    {
        if (rear == front)
            return;
        cout << "Data inside Queue : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1(3);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    // cout << q1.dequeue() << endl;
    // cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    // q1.enqueue(60);

    q1.display();

    return 0;
}

/*

output :

10
Data inside Queue : 20 30

*/