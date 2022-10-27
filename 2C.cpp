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

void bubbleSort(Node *start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main()
{
    Node *head = new Node(0);
    insert(head);
    insert(head);
    print(head);
    bubbleSort(head);
    print(head);

    return 0;
}
