#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

//naive method
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

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
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;
    if (root->data == x)
        return true;
    return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
}

int treeHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int hl = 1 + treeHeight(root->left);
    int hr = 1 + treeHeight(root->right);

    return (hl > hr ? hl : hr);
}

BinaryTreeNode<int> *mirrorNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    BinaryTreeNode<int> *temp;

    //swap
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorNode(root->left);
    mirrorNode(root->right);

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

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    /* BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3); 
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;
    cout << "Total nodes are " << countNodes(root) << endl;
    //printTree(root);
    cout << "Is node x is present?? " << boolalpha << isNodePresent(root, 8) << endl;
    //printTree(root);
    cout << "Height of tree is " << treeHeight(root) << endl;
    // cout<<"Mirror of tree is "<<endl;
    //  mirrorNode(root);
    //  printTreelevelWise(root);
    //  cout<<endl;
    cout << "Inorder Traversal of tree is " << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal of tree is " << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal of tree is " << endl;
    postorder(root);
    delete root;
}
