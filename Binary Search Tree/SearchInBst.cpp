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

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;
    else if (root->data < x)
        return searchInBST(root->right, x);
    else
        return searchInBST(root->left, x);
}

int printRange(BinaryTreeNode<int> *root, int m, int n)
{
    if (root == NULL)
        return -1;
        int res=-1;
    
            if (root->data > m)
        printRange(root->left, m, n);
   
    
    if (root->data >= m && root->data <= n)
    {
        cout << root->data << " ";
         res=1;

    }
 if (root->data <= n )
        printRange(root->right, m, n);
    
    return res;
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
    cout << "Search in Binary tree " << endl;
    int x;
    cout << "Enter element to be search : ";
    cin >> x;
    cout << boolalpha << searchInBST(root, x) << endl;
    cout << "Print range of number " <<endl;
    int res= printRange(root, 6, 10);
if(res==-1)
cout<<"No element is present in given interval.  ";
    delete root;
}
