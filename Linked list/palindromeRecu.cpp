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
bool is_palindrome_rec(Node *head)
{
    Node *p=NULL,*c=NULL,*s=head,*f=head;
    if(head==NULL || head->next==NULL)
    return true;
    while(f && f->next)
    {
        c=s;
        s=s->next;
        f=f->next->next;
        c->next=p;
        p=c;
    }
    if(f)  s=s->next;

    while(p && p->data==s->data)
    {
        p=p->next;
        s=s->next;
    }
    return !p;
    
   
}
//recursive method


int main()
{
    //int n;
    Node *head = TakeInput_better();
    print(head);
    cout << "palindrome ll" << endl;
    
    cout <<is_palindrome_rec(head);

    //   print(head);
}