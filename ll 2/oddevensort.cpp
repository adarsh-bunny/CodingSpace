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
    Node *Ohead = NULL;
    Node *Otail = NULL;
     Node *Ehead = NULL;
    Node *Etail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data); //dynamically created
        if (Ohead == NULL && data%2!=0)
        {
            Ohead = newNode;
            Otail = newNode;
        }
        else if(data%2!=0)
        {
            Otail->next = newNode;
            Otail = Otail->next;
            //or tail=newNode
        }
         if (Ehead == NULL && data%2==0)
        {
            Ehead = newNode;
            Etail = newNode;
        }
        else if(data%2==0)
        {
            Etail->next = newNode;
            Etail = Etail->next;
            //or tail=newNode
        }
        cin >> data;
    }

    Otail->next=Ehead;
    
    return Ohead;
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


//recursive method

int main()
{
    Node *head = TakeInput_better();
  
    cout << "Element after sorting" << endl;
      print(head);
    cout << endl;
}