#include<iostream>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/children-sum-parent/1

// approach -> simply go to each node and check for (every child) sum equal to the node val or not.

struct Node{

    int data;
    Node* left, * right;

};


class Solution{
    
    private:
        int sumProperty(Node* root){
            if(root == NULL)    return 0;
            // leaf Node.
            if(root->left == NULL && root->right == NULL)   return root->data;
            
            
            int leftsubTree = sumProperty(root->left);
            int rightsubTree = sumProperty(root->right);
            
            if(leftsubTree == -1 || rightsubTree == -1)   return -1;
            if(leftsubTree + rightsubTree == root->data)  return root->data;
            return -1;
        }
    
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        int checkProperty = sumProperty(root);
        return checkProperty == -1 ? 0 : 1;
    }
};

int main()
{
    
    return 0;
}