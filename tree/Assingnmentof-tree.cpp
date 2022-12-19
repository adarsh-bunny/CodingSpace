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
       
        cout << endl;
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumNodes(root->children[i]);
    }
    return ans;
}
int largestData(TreeNode<int> *root)
{
    int max = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        int ans = largestData(root->children[i]);
        if (ans > max)
            max = ans;
    }
    return max;
}
int heightOfTree(TreeNode<int> *root)
{
    int max = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int h = heightOfTree(root->children[i]);
        if (h > max)
            max = h;
    }
    return max + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int c = 0;
int countLeafNode(TreeNode<int> *root)
{

    if (root == NULL)
        return 0;

    if (root->children.size() == 0)
    {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        int h = countLeafNode(root->children[i]);
        if (h == 1)
        {
            c += 1;
        }
    }
    return c;
}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
        deleteTree(root->children[i]);
    delete root;
}

bool findX(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;
    if (root->data == x)
        return true;
    bool ans = false;

    for (int i = 0; i < root->children.size(); i++)
    {
        bool h = findX(root->children[i], x);
        if (h == true)
            ans = h;
    }
    return ans;
}
int c2 = 0;
int countNodes(TreeNode<int> *root, int x)
{
    if (root->data > x)
    {
        c2++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
         countNodes(root->children[i], x);
    }

    return c2;
}

TreeNode<int> * maxChild(TreeNode<int>* root)
{
    int sum=root->data;
    TreeNode<int> * ans=root ;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;    
    }
   
     for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> * childmax=maxChild(root->children[i]);
        int smallsum=childmax->data; 
       for(int i=0;i<childmax->children.size();i++)			// calculating sum for max node 
          {
              smallsum+=childmax->children[i]->data;
          }
      
         if(sum<=smallsum)             //comparision  update if necessary
         {
             ans=childmax;	
             sum=smallsum;                           
         }

    }

    return ans;
}

bool structurallyIdentical(TreeNode<int>* r1,TreeNode<int>* r2)
{
     if(r1->children.size() != r2->children.size())
        return false;
     if(r1->data!=r2->data)
       return false;

    bool ans =true;
   

     for(int i=0;i<r1->children.size();i++)
     {
        bool childans= structurallyIdentical(r1->children[i],r2->children[i]);
         if(childans == false)
        {   
            ans=smallans;
            return ans;
        }
     }
     return ans;

    
}
int main()
{

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // TreeNode<int> *root= new TreeNode<int>(1);
    // TreeNode<int> *node1= new TreeNode<int>(2);
    // TreeNode<int> *node2= new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int> *root = TakeInputLevelWise();
    cout << endl;
    cout << "printLevelWise: " << endl;
    printLevelWise(root);
    cout << endl;
    cout << "print horizontally: " << endl;
    printTree(root);

    cout << "number of nodes: " << numNodes(root) << endl;
    cout << "sum of nodes: " << sumNodes(root) << endl;
    cout << "largest value in the node is : " << largestData(root) << endl;
    cout << "height of the tree  : " << heightOfTree(root) << endl;
    cout << "node at level k of the tree  : " << endl;
    printAtLevelK(root, 2);
    cout << "Leaf Node of the tree  : " << countLeafNode(root) << endl;
    cout << "Print preoder : " << endl;
    preorder(root);
    cout << endl;
    cout << "Print postorder : " << endl;
    postorder(root);
    cout << endl;
    cout << "Find if there is element in tree or not ? " << findX(root, 0) << endl;
    cout << "Count number of element in tree greater than x is:  " << countNodes(root, 0) << endl;

    cout << "Max child is :  " << maxChild(root)->data << endl;
     TreeNode<int> *r1 = TakeInputLevelWise();
     TreeNode<int> *r2 = TakeInputLevelWise();
     cout << "Structurally equal or not: " << structurallyIdentical(r1,r2) << endl;


    //delete tree
    cout << "Deleting Tree : " << endl;
    deleteTree(root);
    cout << endl;
}