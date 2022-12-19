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

int findNode_ll_Rec(Node *head, int x )
{
    if (head == NULL )
        return -1;
    if (head->data == x)
        return 0;
    
    int n=findNode_ll_Rec(head->next, x);
    cout<<n<<" ";
    if(n==-1)
      return -1;
    else
      return n+1;
    
}
//recursive method

int main()
{
    int x;
    Node *head = TakeInput_better();
    print(head);
    cin>>x;
    cout << "Element is present at index" << endl;
    int index= findNode_ll_Rec(head, x);
    cout<<index;
    cout << endl;
}