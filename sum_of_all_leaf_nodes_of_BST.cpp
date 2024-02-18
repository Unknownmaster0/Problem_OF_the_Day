#include<iostream>
using namespace std;

int main()
{
    
    return 0;
}

struct Node{
    int data;
    Node *left,*right;
}; 

void inorder(Node* root, int& sum){
    if(root == NULL)    return;
    if(root->left == NULL && root->right == NULL){
        sum += root->data;
        return;
    }
    
    inorder(root->left, sum);
    inorder(root->right, sum);
}

/*You are required to complete below method */
int sumOfLeafNodes(Node *root ){
    /* // Method 1 -> using the inorder separate function
    int sum = 0;
    inorder(root, sum);
    return sum;
    */

    // Method 2 -> using inorder function here only. 
    if(root == NULL)    return 0;
    if(root->left == NULL && root->right == NULL)   return root->data;
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}