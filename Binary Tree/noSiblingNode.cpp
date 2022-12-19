#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
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

void noSiblingNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if(root->left && root->right==NULL)
    {
        cout<<root->left->data<<" ";
        noSiblingNode(root->left);
    }
     else if(root->right && root->left==NULL)
    {
        cout<<root->right->data<<" ";
        noSiblingNode(root->right);
    }
    else 
    {
       noSiblingNode(root->left);
        noSiblingNode(root->right);
    }
    
    
    return;
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;

    cout << " Level order traversal  " << endl;
    levelOrderPrint(root);
    cout<<endl;
    cout << " No siblinhg Node is  " << endl;
    noSiblingNode(root);
     cout<<endl;
    delete root;
}
