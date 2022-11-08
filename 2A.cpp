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
    cout << "Enter data in node : ";
    cin >> d;

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{

    if (head->next == NULL)
        return;

    cout << head->data << " ";
    print(head->next);
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        head = head->next;
    }
    else
    {
        int cnt = 1;
        Node *cur = head;
        Node *pri = NULL;

        while (cnt < position)
        {
            pri = cur;
            cur = cur->next;
            cnt++;
        }

        pri->next = cur->next;
        delete cur;
    }
}

void reverseOrderPrint(Node *head)
{
    if (head->next == NULL)
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

    // deleteNode(4, head);
    // print(head);

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