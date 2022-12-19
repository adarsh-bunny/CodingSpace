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
int length(Node *head) {
  
    if(head==NULL)
        return 0;
    
    return 1+ length(head->next);
    
}
Node* reverseK_Rec(Node* head,int k)
{
   Node* prevptr=NULL;
   Node* currptr=head;
   Node* nextptr;
   int count=0;
   while(currptr && count<k)
   {
       nextptr=currptr->next;
       currptr->next=prevptr;

       prevptr=currptr;
       currptr=nextptr;
       count++;

   }
   if(nextptr)
   {
       head->next=reverseK_Rec(nextptr,k);
   }
   return prevptr;
}

Node* reverseRec(Node* &head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node* newhead=reverseRec(head->next);

    head->next->next=head;
    head->next=NULL;
    return newhead;
}
//recursive method

int main()
{
   int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"After reversing ll"<<endl;
    cin>>n;
    cout<<endl;
    head=reverseK_Rec(head,n);
    print(head); 
}