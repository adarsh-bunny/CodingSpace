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

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int treeHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int hl = 1 + treeHeight(root->left);
    int hr = 1 + treeHeight(root->right);

    return (hl > hr ? hl : hr);
}


int treeDiameter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return 0;
int option1=treeHeight(root->left)+treeHeight(root->right);
int option2=treeDiameter(root->left);
int option3=treeDiameter(root->right);


return max(option1,max(option2,option3));

// order of n2 naive method

}

pair<int,int> heightDiameter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;

    }
 pair<int,int> leftAns=heightDiameter(root->left);
 pair<int,int> rightAns=heightDiameter(root->right);
 int ld=leftAns.second;
 int lh=leftAns.first;
 int rd=rightAns.second;
 int rh=rightAns.first;

 int height=1+max(lh,rh);
 int diameter=max(lh+rh,max(ld,rd));
 pair<int,int> p;
 p.first=height;
 p.second=diameter;
 return p;
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
   
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;
    cout<<"Diameter of the tree is (Naive method) "<<treeDiameter(root)<<endl;
     cout<<"Diameter of the tree is "<<endl;
     pair<int,int> p=heightDiameter(root);
     cout<<"Height of the tree "<<p.first<<endl;
    cout<<"Diameter of the tree "<<p.second<<endl;
     
    delete root;
}
