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
Node * Bubble_Sort(Node *head)
{
     // Write your code here
     if(head==NULL || head->next==NULL)
        return head;
    
    
    for(int i=0;i<length(head);i++)
    {
        Node *curr = head, *prev=NULL;  
        
        while(curr->next)
        {
            if(curr->data>curr->next->data){
         if(prev)
         {
              prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;

            prev=prev->next;

         } 
          else  //is it doent exist it would be head node 
                {
                    head= curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
            }
        
        else
        {
            prev=curr;
            curr=curr->next;
        }

        }


    }  
    
    return head;
    
   
}
//recursive method


int main()
{
    Node *head = TakeInput_better();
    print(head);
    cout << "After sorting node" << endl;
 
    head=Bubble_Sort(head);
     print(head);
}