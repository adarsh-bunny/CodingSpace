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
Node* AppendLastNToFirst(Node *head, int i)
{
    int l=length(head);
    cout<<"lenght="<<l;
     Node *temp=head;
     int count=0;
    while(count!=l-i-1){
        temp=temp->next;
        count++; 
    }
    Node *a=head;
    head=temp->next;
   // Node *a=head;
    temp->next=NULL;
    temp=head;
    count++;
    cout<<"count value="<<count<<endl;
    l=l-1;
     while(count!=l)
    {
    temp=temp->next;
    count++;
     }
    temp->next=a;
    return head;
}
node* append_LinkedList(node* head,int n)
{
    //write your code here
    node *p=head;
    node *q=head;
    for(int i=1;i<length(head)-n;i++)
    {
        p=p->next;
    }
    for(int i=1;i<length(head);i++)
    {
        q=q->next;
    }
    q->next=head;  //circular LL
    head=p->next;
    p->next=NULL; //breaking that circular LL
    
    return head;
    
}

int main()
{
   int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"enter number of element from last to append"<<endl;
    cin>>n;
    head=AppendLastNToFirst(head, n);
    print(head);
}