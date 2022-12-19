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

Node* mid(Node *head)
{
    Node *s = head, *f = head->next;
    if (head == NULL || head->next == NULL)
    {
        cout <<  head->data<<endl;
        return head;
    }

    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
    }
    //cout<<"Mid element is "<<s->data<<endl;
    return s;
}

Node* merge(Node *head1,Node *head2)
{
    Node *fh = NULL, *ft = NULL;
    if (head1->data<head2->data)
    {
       fh=head1;
        ft=head1;
       head1= head1->next;
    }
    else{
        fh=head2;
        ft=head2;
        head2= head2->next;
    }

    while(head1 && head2)
    {
        if (head1->data<head2->data)
        {
            
            ft->next=head1;
            ft=head1;
            head1= head1->next;

        }
        else{
          ft->next=head2;
            ft=head2;
            head2= head2->next;

        }
    }

    while (head1)
    {
        ft->next=head1;
            ft=head1;
            head1= head1->next;
    }
       while (head2)
    {
        ft->next=head2;
            ft=head2;
            head2= head2->next;
    }

    return fh;
}
//recursive method

Node* mergeSort(Node *head) {
    //write your code here
   if(head==NULL|| head->next==NULL)
        return head;
     
     //breaking node into two half  
    Node *p=head;
    for(int i=0;i<(length(head)-1)/2;i++)
    {
        p=p->next;
    }
    //p=mid(head);

    Node *head1=p->next;
    p->next=NULL;
    
  head=mergeSort(head);
    head1=mergeSort(head1);
    
    return merge(head,head1);
    
}

int main()
{
    //int n;
    Node *head = TakeInput_better();
    print(head);
  head=mergeSort(head);
    print(head);

    //   print(head);
}