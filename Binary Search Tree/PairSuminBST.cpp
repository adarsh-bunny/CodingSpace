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

void printNodesSumToS(BinaryTreeNode<int> *root, int s) 
{
    if(root==NULL)
        return;
    
    stack<BinaryTreeNode<int>*> s1, s2;
    BinaryTreeNode<int>* p = root;
    BinaryTreeNode<int>* q = root;
    
    while(!s1.empty() || !s2.empty() || p || q){
        if(p || q){
            if(p){
                s1.push(p);
                p = p->left;
            }
            if(q){
                s2.push(q);
                q = q->right;
            }
        }
        else{
            int a = s1.top()->data;
            int b = s2.top()->data;
            
            if(s1.top() == s2.top()) break;
            
            if(a + b == s){
                cout<<min(a, b)<<' '<<max(a, b)<<endl;
            }
            
            if(a + b > s){
                q = s2.top();
                s2.pop();
                q = q->left;
            }
            else{
                p = s1.top();
                s1.pop();
                p = p->right;
            }
        }
    }
    
    // Write your code here
}

//Using inorder traversal
void helper(BinaryTreeNode<int> *root, vector<int> &arr){
	if(root == NULL){
        return;
    }
    
    arr.push_back(root -> data);
    
    helper(root -> left, arr);
    helper(root -> right, arr);
}

void printNodesSumToS1(BinaryTreeNode<int> *root, int s) {
    
    vector<int> output;    
    helper(root, output);
    
    sort(output.begin(), output.end());
    
    int i = 0; int j = output.size() - 1;
    while(i < j){
        
        if(output[i] + output[j] > s){
            j--;
        }
        else if(output[i] + output[j] < s){
            i++;
        }
        else{
            cout << output[i] << " " << output[j] << endl;
            i++;
            j--;
        }
    }

}




    int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreelevelWise(root);
    cout << endl;

    cout << " Level order traversal  " << endl;
    levelOrderPrint(root);
      cout << endl;
 cout << "Pair sum in BST  " << endl;

  printNodesSumToS(root,12);
   
    delete root;
}
