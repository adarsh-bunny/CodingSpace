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
    cout << root->data << "\n";
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

BinaryTreeNode<int> * insertDuplicate(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return NULL;

    insertDuplicate(root->left);
    insertDuplicate(root->right);
    BinaryTreeNode<int> *node=new BinaryTreeNode<int>(root->data);
    node->left=root->left;
    root->left=node; 

    return root;

}
int k=0;

void convert (BinaryTreeNode<int> *root,int *arr)
{
    if(root==NULL)
        return;
    arr[k++]=root->data;
    
    convert(root->left,arr);
    convert(root->right,arr);
    
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
   int arr[1001];
    
    convert(root,arr);
    
    sort(arr,arr+k);
    
    int i=0;
    int j=k-1;
    
    while(i<j)
    {
        if(arr[i]+arr[j]==sum)
        {
            cout<< arr[i] <<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] > sum)
        {
            j--;
        }
        else if(arr[i]+arr[j] < sum)
        i++;
    }
  
}

int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum){
    
    if(root == NULL){
        return sum;
    }
    
    sum = replaceWithLargerNodesSum(root -> right, sum);
    
    sum += root -> data;
    root -> data = sum;
    
    sum = replaceWithLargerNodesSum(root -> left, sum);
    
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
	
    int sum = 0;
    replaceWithLargerNodesSum(root, sum);
    
}


    int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;

    cout << " Level order traversal  " << endl;
    levelOrderPrint(root);
 cout << " Pair having sum = 15  " << endl;
   nodesSumToS(root,15);
   replaceWithLargerNodesSum(root);
      printTreelevelWise(root);
    delete root;
}
