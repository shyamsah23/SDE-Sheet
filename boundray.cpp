#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

// Left Part Of The Tree

void leftTree(Node* root,vector<int> & ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left)
    {
        ans.push_back(root->data);
        leftTree(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        leftTree(root->right,ans);
    }
}

 // right Part Of Tree In reverse order

void rightTree(Node* root,vector<int> & ans)
{
    if(root==NULL)
    {
        return;
    }

    if(root->right)
    {
        rightTree(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        rightTree(root->left,ans);
        ans.push_back(root->data);
    }
}


// Leave Node of LeftSubtree

void leaveLeftTree(Node* root,vector<int> & ans)
{
    if(root==NULL)
    {
        return;
    }

    leaveLeftTree(root->left,ans);
    leaveLeftTree(root->right,ans);
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
    }
}

// Leave Node of RightSubtree

void leaveRightTree(Node* root,vector<int> & ans)
{
    if(root==NULL)
    {
        return;
    }

    leaveRightTree(root->left,ans);
    leaveRightTree(root->right,ans);
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
    }
}

void boundaryTraversal(Node* root,vector<int> & ans)
{
    if(root==NULL)
    {
        return;
    }

    ans.push_back(root->data);

    // Left Part Of The Tree
    leftTree(root->left,ans);

    // Leave Node of LeftSubtree

    leaveLeftTree(root->left,ans);

    // leaves Node of right Subtree
    leaveRightTree(root->right,ans);

    // right Part Of Tree In reverse order

    rightTree(root->right,ans);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // Boundary Order Traversal

    vector<int> ans;

    boundaryTraversal(root,ans);

    for(auto it:ans)
    {
        cout<<it<<" ";
    }

    return 0;
}