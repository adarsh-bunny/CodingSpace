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
Node* add1(Node* &head)
{
    if(head->next==NULL && head->data!=9)
    {
        head->data=head->data+1;
        return;
    }
    else if(head->next==NULL && head->data==9)
    {

    }
  
   
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
   //int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"After reversing ll"<<endl;
    //cin>>n;
    head=reverse(head);
    cout<<endl;
   // print_linkedlist_spl(head);
    print(head);
    cout<<endl;
    head=reverseRec(head);
    print(head); 
}