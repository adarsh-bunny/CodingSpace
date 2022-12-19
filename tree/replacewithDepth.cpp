#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *TakeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNode;

    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << "Enter number child of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "ith child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
TreeNode<int> *takeInput()
{
    int rootdata, n;
    cout << "Enter data" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    cout << "Enter number of children of " << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        TreeNode<int> *front = pendingQ.front();
        cout << front->data << ":";
        pendingQ.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);

            if (root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << ",";
            }
            else
            {
                cout << root->children[i]->data;
            }
        }
        root = pendingQ.front();
        cout << endl;
    }
}

TreeNode<int> *replaceWithDepth(TreeNode<int> *root,int depth){
               
if (root == NULL)
        return NULL;
    
    root->data=depth;
    for(int i=0;i<root->children.size();i++)
    {
        replaceWithDepth(root->children[i],depth+1);

    }
return root;

}


int main()
{

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int> *root = TakeInputLevelWise();
    cout << endl;
    cout << "printLevelWise: " << endl;
    printLevelWise(root);
    cout << endl;
    replaceWithDepth(root,0);
    cout << "After replacement : " << endl;
     printLevelWise(root);



    //delete tree
    cout << "Deleting Tree : " << endl;

    cout << endl;
}