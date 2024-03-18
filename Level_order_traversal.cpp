#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/level-order-traversal/1


// Code -> 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    // t.c = O(number of nodes) || s.c = O(number of nodes)
    vector<int> levelOrder(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                Node* node = q.front();
                ans.push_back(node->data);
                
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        return ans;
    }
};

int main()
{
    
    return 0;
}