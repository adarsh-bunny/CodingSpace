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
//NAIVE METHOD
int maximum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }

    return max(root->data ,max(maximum(root->left),maximum(root->right)));

}

int minimum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }

    return min(root->data ,min(minimum(root->left),minimum(root->right)));
    
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
       
       int leftmax=maximum(root->left);
       int rightmin=minimum(root->right);

       bool output= ((root->data>leftmax) && (root->data<=rightmin) && isBST(root->left) && isBST(root->right));
  
    
    return output;
}

class isBSTReturn{
    public:
    int maximum;
    int minimum;
    bool isBST;
};

isBSTReturn  isBST2(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        isBSTReturn output;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        output.isBST=true;
        return output;
    
    }

    isBSTReturn leftTree= isBST2(root->left);
    isBSTReturn rightTree=isBST2(root->right);
    isBSTReturn output;
    output.minimum= min(root->data,min(leftTree.minimum,rightTree.minimum));
    output.maximum= max(root->data,max(leftTree.maximum,rightTree.maximum));
    output.isBST=( (root->data >leftTree.maximum)&& (root->data <=rightTree.minimum) && leftTree.isBST && rightTree.isBST);
    return output;


};

// method 3

bool isBST3(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
    return true;
  if(root->data<min || root->data > max)
  return 0;
    bool isleftOK=isBST3(root->left,min,root->data-1);
    bool isrigthOK=isBST3(root->right,root->data,max);
    return isleftOK && isrigthOK;
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
    cout << "Is Binary tree or not?" << endl;
    cout << boolalpha << isBST(root) << endl;
       cout << "Is Binary tree or not? (optimised)" << endl;
     isBSTReturn output= isBST2(root);
    cout << boolalpha << output.isBST << endl;
    cout << "Is Binary tree or not? (method 3) top to down " << endl;
    cout << boolalpha << isBST3(root) << endl;
   
    delete root;
}
