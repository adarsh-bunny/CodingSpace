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
Node* swap(Node *head,int M,int N)
{
     // Write your code here
    if(M==0)
        return NULL;
    node *t1 = head, *t2=head;  
    while(M)
    {
       t1=t1->next;

    }
    while(N)
    {
       t2=t2->next;
       
    }
    int d=t1->data;
    t1->data=t2->data;
    t2->data=d;
    return head;
    
   
}
//recursive method


int main()
{
    int m,n;
    Node *head = TakeInput_better();
    print(head);
    cout << "After deleting node" << endl;
    cin>>m>>n;
    
    cout <<swap(head,m,n);

    //   print(head);
}