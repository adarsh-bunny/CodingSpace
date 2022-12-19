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
static int c=0;
Node* TakeInput_better()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        c++;
        Node *newNode= new Node(data);//dynamically created
        if(head==NULL)
        {
              head=newNode;
              tail=newNode;

        }
        else{
           tail->next=newNode;
           tail=tail->next;
           //or tail=newNode 
        }
        cin>>data;
    }
    return head;

}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int length(Node *head) {
  
    if(head==NULL)
        return 0;
    
    return 1+ length(head->next);
    
}
int find_element(Node *head,int i,int l)
{
    if(l<i)
    return -1;

    int temp=i;
    while(temp--)
    {
        head=head->next;
    }

    return head->data;

}

int main(){
    int t,k;
    cin>>t;
    while(t--)
    {
      //  c=0;
         Node *head= TakeInput_better();
         print(head);
         cout<<endl;
         cin>>k;
     
    // cout<<"\n length of linked list = "<<c<<endl;
    int l=length(head);
    cout<<"\n length of linked list recurcively = "<<l<<endl;
    cout<<"The element in the linked list is = "<<find_element(head,k,l)<<endl;


    }
   


}