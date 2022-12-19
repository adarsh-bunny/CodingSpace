#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *TakeInput_better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data); //dynamically created
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            //or tail=newNode
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int length(Node *head)
{

    if (head == NULL)
        return 0;

    return 1 + length(head->next);
}
int palindrome_iter(Node *head)
{
    //write your code here
    Node *tail = head;
    Node *p = head;
    int l = length(head);
    for (int i = l - 1; i >ceil(l/2); i--)
    {
        int n = i;
        while (n)
        {
            tail = tail->next;
            n--;
        }
        if (tail->data == p->data)
        {
            tail =head;
            p = p->next;
        }
        else if (tail->data != p->data)
        {
            return -1;
        }
    }
    return 1;

    cout << endl;
}
//recursive method

int main()
{
    //int n;
    Node *head = TakeInput_better();
    print(head);
    cout << "palindrome ll" << endl;
    //cin>>n;
    cout << palindrome_iter(head);

    //   print(head);
}