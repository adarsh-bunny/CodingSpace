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
Node* deleteAlternateNode(Node* head)
{
    if(head==NULL || head->next==NULL)
 {
     return head;
 }
Node *temp=deleteAlternateNode(head->next->next);

Node *a=head->next;
head->next=temp;
delete a;
return head;

}


int main()
{
   //int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"After deleting Alternate Node in ll"<<endl;
    //cin>>n;
    head=deleteAlternateNode(head);
     print(head);
    cout<<endl;
}