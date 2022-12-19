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
void mid(Node *head)
{
    Node *s = head, *f = head->next;
    if (head == NULL || head->next == NULL)
    {
        cout <<  head->data<<endl;
        return;
    }

    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
    }
    cout<<"Mid element is "<<s->data<<endl;
    return ;
}
//recursive method

int main()
{
    //int n;
    Node *head = TakeInput_better();
    print(head);
    cout << "call mid fn" << endl;
       mid(head);

    //   print(head);
}