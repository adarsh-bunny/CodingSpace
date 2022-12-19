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
Node* insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        newNode->next=head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
        
    }

    // newNode->next = temp->next;
    // temp->next=newNode;
    //  print(head);

    // or
    if ((temp != NULL))
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    
    }

   // print(head);
    return head;
}


Node* deleteNode(Node *head, int i)
{
    
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        Node *a=head;
        head=head->next;
        delete a;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
        
    }

    if ((temp != NULL))
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
    
    }

   // print(head);
    return head;
}
int main()
{
    int k,i;
    Node *head = TakeInput_better();
    print(head);
   // cout<<"Enter position to Delete number in the node"<<endl;
   // cin>>i;
    //head=insertNode(head, 0, 99);
    //print(head);
    cout<<"Enter position to Delete number in the node"<<endl;
    cin>>k;
    head=deleteNode(head, k);
    print(head);
}