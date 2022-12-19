using namespace std;

template<typename T>
class BinaryTree{
    public:
    T data;
  BinaryTreeNode * left;
  BinaryTreeNode * right;

    BinaryTree(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
   ~TreeNode()  
    {
        delete left;
        delete right;
    } 
};