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
Node* swap(Node *head,int i,int j)
{
     cout<<" swapping "<<"\n";
     // Write your code here

    Node* p1 = head,*temp=head,*prev=NULL;
    Node* p2=head,*c1=NULL,*c2=NULL; 
    
    int count=0;
   while(temp!=NULL)
    {
        if(count==i)
        {
          c1=temp;
          p1=prev;
            
        }
        else if(count==j)
        {
          c2=temp;
          p2=prev;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
   
  if(p1!=NULL)
        p1->next=c2;
    else
        head=c2;
    
    if(p2!=NULL)
        p2->next=c1;
    else
        head=c1;
    Node * p=c2->next;
    c2->next= c1->next;
     c1->next= p;
   
 
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
    
    head=swap(head,m,n);

       print(head);
}