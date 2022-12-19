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


int nextLarge(TreeNode<int> *root,int x)
{    
    if(root==NULL)
    return 0;
    int ans=0;
    
    if(root->data>x)
    {
     ans= root->data;
    }
    
    for(int i=0;i<root->children.size();i++)
    {
        int res=nextLarge(root->children[i],x);              
        if(res==0)
        {
            continue;     
        }
        else 
        {
            if(ans==0)
            ans =res;
            else if(ans>res)
               ans=res;   
    }
    }
    return ans;
    

}



class helper {
  public :
    TreeNode<int>*  m;
    TreeNode<int>* sm;
    
    helper (TreeNode<int>* m, TreeNode<int>* sm) {
        this->m = m;
        this->sm = sm;
    }
};
helper help (TreeNode<int>* root) {
    if(root==NULL){
        helper r(NULL,NULL);
        return r;
    }
    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++) {
            helper child = help (root -> children[i]);  
            if(child.m->data > ans.m->data){
                if(child.sm==NULL){
                    ans.sm=ans.m;
                    ans.m=child.m;
                }
                else{
                    if(child.sm->data > ans.m->data){
                        ans.sm=child.sm;
                        ans.m=child.m;
                    }
                    else{
                       ans.sm=ans.m;
                        ans.m=child.m; 
                    }
                }
            }
        else {
            if(ans.m->data!=child.m->data && (ans.sm==NULL || child.m->data > ans.sm->data)){
                ans.sm=child.m;
            }
        }
        }
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    
    if (root == NULL) return NULL;
    helper ans = help (root);
    return ans.sm;
}



class Secondmax{
    public:
    int max=-1;
    int ans=-1;


};
Secondmax findSecondMax(TreeNode<int> *root){
  
   
      if(root==NULL){
        Secondmax r;
        r.max=-1;
        r.ans=-1;
        return r;
    }
    Secondmax res;
    res.max=root->data;
    res.ans=-1;

    for(int i=0;i<root->children.size();i++)
    {
         Secondmax temp=findSecondMax(root->children[i]);

        if(res.max<temp.max)
        {
            int t=res.max;
            res.max=temp.max;
            if(res.ans<t && t>temp.ans)
            res.ans=t;
            else if(temp.ans>res.ans && t<temp.ans)
        res.ans=temp.ans;

        }
        else if(res.max>temp.max)
        {
             if(res.ans<temp.max && temp.max>temp.ans)
            res.ans=temp.max;
            else if(res.ans<temp.ans && temp.max<temp.ans )
        res.ans=temp.ans;

        }

    }
    return res;
}

int main()
{

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int> *root = TakeInputLevelWise();
    cout << endl;
    cout << "printLevelWise: " << endl;
    printLevelWise(root);
    cout << endl;
    int x;
    
    cout << "next large number  : " << endl;
    cin>>x;
    int ans=nextLarge(root, x);
    if(ans!=0)
    cout<<"next large number is "<<ans<<endl;
    else
    cout<<"No next element is present"<<endl;
    cout<<"Finding second largest number "<<endl;
    Secondmax s= findSecondMax(root);
    if(s.ans!= -1)
    cout<<"second largest number "<<s.ans<<endl;
    else
    cout<<"No SECOND LARGEST  element is present"<<endl;
    //delete tree
    cout << "Deleting Tree : " << endl;
    cout << endl;
}