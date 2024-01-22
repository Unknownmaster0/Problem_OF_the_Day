#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

struct Node
{
	int key;
	struct Node *left, *right;
};

    void inorder(vector<vector<int>>&ans, vector<int>&temp, Node* root, int&s, int&target){
        
        if(root == NULL){
            return ;
        }
        
        // first push the element and check if this is equal to the target sum or not.
        temp.push_back(root->key);
        s += root->key;
        
        if(s == target){
            ans.push_back(temp);
        }

        inorder(ans, temp, root->left, s, target);
        
        inorder(ans, temp, root->right, s, target);
        // backtracking steps.
        s -= root->key;
        temp.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int>temp;
        int s = 0;
        inorder(ans, temp, root, s, sum);
        return ans;
    }

int main()
{
    
    return 0;
}