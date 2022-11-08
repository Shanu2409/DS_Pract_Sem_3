#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int value)
    {

        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Overflow can't store value : " << value << endl;
            return;
        }

        if (rear == -1)
            front = rear = 0;

        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;

        arr[rear] = value;
        return;
    }

    int dequeue()
    {
        if (front == -1)
            return -1;

        int ans = arr[front];

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty" << endl;
            return;
        }
        cout << "\nElements in Circular Queue are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
    }
};

int main()
{
    CircularQueue q1(3);

    q1.enqueue(5);
    q1.enqueue(3);
    q1.enqueue(2);
    cout << q1.dequeue();
    cout << q1.dequeue();
    cout << q1.dequeue();
    cout << q1.dequeue();
    q1.enqueue(6);
    cout << q1.dequeue();

    return 0;
}