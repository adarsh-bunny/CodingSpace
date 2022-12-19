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
Node* insertNodeRecursive(Node *head, int i, int data)
{
    
    if(i==0){
        Node *newNode=new Node(data);
         newNode->next=head;
         head=newNode;
        return head;      
    }
    if(head==NULL || i<0)   return head;

    Node *temp=insertNodeRecursive(head->next,i-1,data);
    head->next=temp;
    return head;


}
Node* deleteNodeRec(Node *head, int i) {
  
    if(head==NULL ||i<0)
        return head;
    if(i==0)
    {
        Node *p=head;
        head=p->next;
        delete p;
        return head;
    }
    Node *x=deleteNodeRec(head->next,i-1);
    head->next=x;
    x=head;
    return head;
}

int main()
{
    int k;
    Node *head = TakeInput_better();
    print(head);
    cout<<"enter position to delete"<<endl;
    cin>>k;
  //  head=insertNodeRecursive(head, k, 99);
   head=deleteNodeRec(head,  k)
    print(head);
}