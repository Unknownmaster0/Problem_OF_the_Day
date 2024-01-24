#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    void dfs(TreeNode*root ,vector<int>&arr, int& count){
        if(root->left == NULL && root->right == NULL){
            // then check the elements in map.
            int countone = 0;
            // traverse on whole map and check the freq of elements
            for(int i = 1; i<=9; i++){
                if(arr[i] % 2 != 0) countone++;
            }
            // if the total freq is not equal to the freqsize
            if(countone <= 1)    count ++; 
            return;
        }

        //call left
        if(root->left){
            arr[root->left->val]++;
            dfs(root->left, arr, count);
            arr[root->left->val] --;
        }
        //call right
        if(root->right){
            arr[root->right->val]++;
            dfs(root->right, arr, count);
            arr[root->right->val]--;
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>arr(10, 0);
        int count = 0;
        arr[root->val]++;
        dfs(root, arr, count);
        return count;
    }

int main()
{
    
    return 0;
}