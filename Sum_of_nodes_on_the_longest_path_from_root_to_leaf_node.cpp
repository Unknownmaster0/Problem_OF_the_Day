#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// code ->
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    // mps -> maxPathsum, mph -> maxPathHeight
    int mps = 0, mph = 0;
    
    void inorder(Node* root, int ps, int pl){
        
        if(root == NULL)    return;
        
        // when only the encounter the leaf node, then only update the maxPathsum and maxPathlength
        ps += root->data;
        if(root->left == NULL && root->right == NULL){
            
            if(pl > mph){
                mph = pl;
                mps = ps;
            }
            else if(pl == mph){
                mps = max(mps, ps);
            }
            return;
        }
        
        //left call
        inorder(root->left, ps, pl+1);
        // right call
        inorder(root->right, ps, pl+1);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        inorder(root, 0, 0);
        return mps;
    }
};

int main()
{

    return 0;
}