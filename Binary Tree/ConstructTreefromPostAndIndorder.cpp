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

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    return;
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *post, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
        return NULL;
int rootIndex=-1;
for (int i = inS; i <=inE; i++)
    {
        if (post[postE] == in[i])
        {
            rootIndex = i;
            break;
        }
    }
    int rootData = in[rootIndex];
    
    int lInS = inS;
    int lInE = rootIndex -1 ;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE-1;
    int rInS = rootIndex+1;
    int rInE = inE;
     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, post, lInS, lInE ,lPostS, lPostE);
    root->right = buildTreeHelper(in, post, rInS, rInE, rPostS, rPostE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *in, int *post, int size)
{
    return buildTreeHelper(in, post, 0, size - 1, 0, size - 1);
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

    int post[] = {4, 5 ,2, 6, 7, 3, 1 };
    int in[] = {4, 2, 5, 1, 6, 3 ,7};
    BinaryTreeNode<int> *root = buildTree(in, post, 7);
    printTreelevelWise(root);
    cout << endl;
    inorder(root);
    delete root;
}
