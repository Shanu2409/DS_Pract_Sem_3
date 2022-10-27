#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int value)
    {
        // to check whther queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {

            cout << "Overflow!! can't store value : " << value << endl;
            return;
        }
        else if (front == -1) // first element to push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear++;
        }

        arr[rear] = value;

        return;
    }

    int dequeue()
    {
        if (front == -1)
        { // to check queue is empty
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
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
    q1.enqueue(8);

    cout << q1.dequeue();

    q1.enqueue(19);

    q1.display();

    return 0;
}