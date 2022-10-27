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

int search(int key, Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp->data != key)
    {
        if (temp->next == NULL)
            return -1;
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

int main()
{
    Node *head = new Node(0);

    insert(head);
    insert(head);
    insert(head);
    insert(head);

    int key;

    cout << "Enter number to find in list : ";
    cin >> key;

    int ans = search(key, head);

    if (ans == -1)
        cout << "not found" << endl;
    else
        cout << "Found at " << ans + 1 << " this node" << endl;

    return 0;
}

/*

output :

Enter data in Node : 4
Enter data in Node : 3
Enter data in Node : 2
Enter data in Node : 1
Enter number to find in list : 3
Found at 3 this node


*/