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
Node * delete_n_Node(Node *head,int M,int N)
{
     // Write your code here
    if(M==0)
        return NULL;
    node *curr = head, *t;  
    int count;  
    // The main loop that traverses 
    // through the whole list  
    while (curr != NULL)  
    {  
        // Skip M nodes  
        for (count = 1; count < M &&  curr!= NULL; count++)  
            curr = curr->next;  
        // If we reached end of list, then return  
        if (curr == NULL)  
            return head;  
        // Start from next node and delete N nodes  
        t = curr -> next;  
        for (count = 1; count <= N && t != NULL; count++)  
        {  
            node *temp = t;  
            t = t -> next;  
            free(temp);  
        }  
        // Link the previous list with remaining nodes  
        curr -> next = t;  
        // Set current pointer for next iteration  
        curr = t;  
    }
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
    
    cout <<delete_n_Node(head,m,n);

    //   print(head);
}