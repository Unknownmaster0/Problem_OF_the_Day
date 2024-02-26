#include<iostream>
using namespace std;

// Problem link -> https://leetcode.com/problems/same-tree/?envType=daily-question&envId=2024-02-26

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       // use the inorder traversal of the tree. 
        if(p == NULL && q == NULL)  return true;
        if(p == NULL && q != NULL)  return false;
        if(p != NULL && q == NULL)  return false;

        bool left = isSameTree(p->left, q->left);
        if(p->val != q->val)    return false;
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }
};

int main()
{
    
    return 0;
}