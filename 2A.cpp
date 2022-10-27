#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insert(Node *&head)
{
    int d;

    cout << "Enter data in Node : ";
    cin >> d;

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int position, Node *&head)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void reverseOrderPrint(Node *head)
{
    if (head == NULL)
        return;

    reverseOrderPrint(head->next);

    cout << head->data << " ";
}

int main()
{
    Node *n1 = new Node(5);

    Node *head = n1;

    insert(head);
    insert(head);
    insert(head);
    insert(head);

    cout << "Printing in normal order : ";
    print(head);
    cout << endl;

    cout << "Printing in reverse order : ";
    reverseOrderPrint(head);

    return 0;
}

/*

output :

Enter data in Node : 4
Enter data in Node : 3
Enter data in Node : 2
Enter data in Node : 1
Printing in normal order : 1 2 3 4 5

Printing in reverse order : 5 4 3 2 1


*/