#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
    int data;
    Node *next;
   
    Node(int data){
        this->data=data;
        next=NULL;
    } 

};

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
//     //statically
//     Node n1(1);
//     Node *head=&n1;

//     Node n2(2);
//     Node n3(3);
//     n1.next=&n2;
//   n2.next=&n3;
//   print(head);

  //dynamically
  Node *n4=new Node(10);
  Node *head=n4;
  Node *n5=new Node(11);
  Node *n6=new Node(12);
  Node *n7=new Node(13);
  n4->next=n5;
  n5->next=n6;
 n6->next=n7;
print(head);

}