bool check(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if( (root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL) )
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    
    bool left=check(root1->left,root2->right);
    bool right=check(root1->right,root2->left);
    
    return left && right;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
     
    
     bool ans=check(root,root);
    return ans;
    
    
    
}