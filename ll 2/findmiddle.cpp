#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;

    }
};



Node *take_input()
{
  
    Node *head=NULL;
     int data;
    cin>>data;
    Node *tail=NULL;
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
int len(Node *head){
    if(head==NULL)
    return 0;

    return 1+len(head->next);

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

void find_element(Node *head)
{
    Node *temp=head;
    for(int i=0;i<(len(head)-1)/2;i++)
    {
        temp=temp->next;
    }
   cout<<temp->data<<endl;
}

int main()
{
    Node *head = take_input();
    print(head);
    cout << "length= " <<len(head)<< endl;
    find_element(head);
 
    // head=Bubble_Sort(head);
    //  print(head);
}