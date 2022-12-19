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
void reverse(Node* head)
{
    //write your code here
    Node *tail=head;
    int l=length(head);
    for(int i=l-1;i>=0;i--)
    {
        int n=i;
         while(n) 
    {
        tail=tail->next;
        n--;
    }
    cout<<tail->data<<" ";
    tail=head;

    }

    cout<<endl;
}
//recursive method
void print_linkedlist_spl(Node*head)
{
    if (head == NULL)  
    return;  
  
    // print the list after head node  
    print_linkedlist_spl(head->next);  
  
    // After everything else is printed, print head  
    cout << head->data << " ";  
}
int main()
{
   //int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"After rreversing ll"<<endl;
    //cin>>n;
    reverse(head);
    cout<<endl;
    print_linkedlist_spl(head);
 //   print(head);
}