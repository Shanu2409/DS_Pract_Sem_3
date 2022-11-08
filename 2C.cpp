#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pri;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
        this->pri = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head->next;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(Node *&head)
{
    int d;

    cout << "Enter data in Node : ";
    cin >> d;

    Node *temp = new Node(d);

    temp->pri = head;
    temp->next = head->next;
    head->next = temp;
}

void bubbleSort(Node *&head)
{
    int swapped, i;
    Node *temp;
    Node *lptr = NULL;

    // if (head == NULL)
    //     return;

    do
    {
        temp = head;
        swapped = 0;

        while (temp->next != lptr)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
                swapped = 1;
            }
            temp = temp->next;
        }

        lptr = temp;
    } while (swapped);
}

int main()
{
    Node *head = new Node(0);
    insert(head);
    insert(head);
    insert(head);
    print(head);
    bubbleSort(head);
    print(head);

    return 0;
}
