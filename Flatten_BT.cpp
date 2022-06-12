/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void  solve(TreeNode<int> * &root)
{
    if(root==NULL)
    {
        return;
    }
    
    solve(root->left);
    solve(root->right);
    
    TreeNode<int> * temp=root->right;
    root->right=root->left;
    root->left=NULL;
    
    TreeNode<int> * x=root;
    while(x->right!=NULL)
    {
        x=x->right;
    }
    
    x->right=temp;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    solve(root);
    
    return root;
    
}