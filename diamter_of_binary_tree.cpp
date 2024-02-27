#include <iostream>
using namespace std;

// Problem link ->  https://leetcode.com/problems/diameter-of-binary-tree/?envType=daily-question&envId=2024-02-27

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL, right = NULL;
    }
};

class Solution {
// finding the height of any node in a tree.
// t.c = O(n)
    int findHeight(TreeNode* root, int &maxi){
        if(root == NULL)
            return 0;

        int lh = findHeight(root->left, maxi);  // left height
        int rh = findHeight(root->right, maxi); // right height

        maxi = max(maxi, lh+rh); // this extra line is added to make the code optimal and finding the diameter.

        return 1+max(lh, rh); // returning the height of the tree.
    }
/*// t.c = O(n^2) [n = number of nodes.]
    void diameter(TreeNode* root, int& maxi){
        if(root == NULL)    return;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        maxi = max(maxi, lh + rh);

        diameter(root->left, maxi);
        diameter(root->right, maxi);
    }
*/
public:
int maxi = -1e8;
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = -1e9;
        // method 1 -> naive approach -> t.c = O(n ^ 2)
        // diameter(root, maxi);

        // method 2 -> optimal one -> t.c = O(n) [using only the find height function]
        findHeight(root, maxi);
        return maxi;
    }
};

int main()
{

    return 0;
}