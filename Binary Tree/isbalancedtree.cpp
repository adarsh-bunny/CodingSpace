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

int treeHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int hl = 1 + treeHeight(root->left);
    int hr = 1 + treeHeight(root->right);

    return (hl > hr ? hl : hr);
}
bool isBalancedTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    else
    {
        isBalancedTree(root->left);
        isBalancedTree(root->right);
    }

    return true;
}

pair<int, bool> isBalancedHelper(BinaryTreeNode<int> *root)
{
    pair<int, bool> ans;
    if (root == NULL)
    {
        ans.first = 0;
        ans.second = true;
        return ans;
    }

    pair<int, bool> l = isBalancedHelper(root->left);
    pair<int, bool> r = isBalancedHelper(root->right);

    ans.first = 1 + max(l.first, r.first);
    ans.second = (l.second && r.second);
     if (!ans.second)
    {
        return ans;
    }
    if (abs(l.first - r.first) > 1)
    {
        ans.second = false;
        return ans;
    }

    return ans;
}

bool isBalancedTreeOptimised(BinaryTreeNode<int> *root)
{
    pair<int, bool> ans = isBalancedHelper(root);
    return ans.second;
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;

    cout << "Is tree is balanced ? " << boolalpha << isBalancedTree(root) << endl;
    cout << "Is tree is balanced(optimised) ? " << boolalpha <<  isBalancedTreeOptimised(root) << endl;
   
    delete root;
}
