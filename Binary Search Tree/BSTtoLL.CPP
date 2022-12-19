#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

void printTreelevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingQ.front();
        cout << front->data << ":-";
        pendingQ.pop();
        if (front->left)
        {
            pendingQ.push(front->left);
            cout << "L:" << front->left->data << ",";
        }
        else
            cout << "L:"
                 << "-1"
                 << ",";

        if (front->right)
        {
            pendingQ.push(front->right);
            cout << "R:" << front->right->data << ".";
        }
        else
            cout << "R:"
                 << "-1";

        cout << endl;
    }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void levelOrderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
   
    queue<BinaryTreeNode<int> *> pendingQ;
    pendingQ.push(root);
    pendingQ.push(NULL);
    while (pendingQ.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingQ.front();
        pendingQ.pop();
        if (front != NULL)
        {
            cout << front->data << " ";
            if (front->left)
                pendingQ.push(front->left);

            if (front->right)
                pendingQ.push(front->right);
        }
        else
        {
            if (pendingQ.size() == 0)
                break;

            pendingQ.push(NULL);
            cout << "\n";
        }
    }
    return;
}
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }

}
pair<Node*,Node*> BSTtoLL(BinaryTreeNode<int>* root)
{
    pair<Node*,Node*> output;
   if(root==NULL)
   {
       output.first=NULL;
       output.second=NULL;
       return output;      
   }
    pair<Node*,Node*> leftTree= BSTtoLL(root->left);
    pair<Node*,Node*> rightTree= BSTtoLL(root->right);




    return output;

}

class Pair{
  public:
    Node <int>*head;
    Node <int>*tail;
};

Pair BST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair ans ;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;

    }
    
	Node<int> *node= new Node<int> (root->data);
    
    Pair leftans=BST(root->left);
    Pair rightans=BST(root->right);
    
    
    Pair ans;
    
    if(leftans.head==NULL && rightans.head==NULL)
    {
        
        ans.head=node;
        ans.tail=node;
       
    }
    
   else if(!leftans.head && rightans.head  )
   		 { ans.head=node;
           node->next=rightans.head;
   		     
        	ans.tail=rightans.tail;
  		  }
  else if(leftans.head && rightans.head==NULL)
  		  { ans.head=leftans.head;
      			leftans.tail->next=node;
  		        ans.tail=node;
               
  		  }
    else
    {
        ans.head=leftans.head;
        leftans.tail->next=node;
        node->next=rightans.head;
        ans.tail=rightans.tail;
    }
    
    
    
     return ans;
     
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {
   return BST(root).head;
    
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;
 
    cout << "Level order traversal  " << endl;
    levelOrderPrint(root);
    cout << endl;
    int n=7;
  //  cin>>n;
    int a[]={1 ,2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int> *root1=constructTree(a,0,n-1);
     levelOrderPrint(root1);
        delete root;
}
