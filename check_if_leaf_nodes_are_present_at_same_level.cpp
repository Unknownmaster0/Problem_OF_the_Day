#include<iostream>
#include<queue>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

struct Node{
    int data;
    Node* left, * right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

    bool check(Node *root)
    {
        // use normal level order traversal of the tree.
        queue<pair<Node*, int>> q;
        q.push({root,0});
        
        int leafLvl = 0;
        
        // Time complexity -> O(Number of nodes.)
        while(!q.empty())
        {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node->left == NULL && node->right == NULL){
                if(leafLvl == 0)    leafLvl = level;
                else{
                    if(leafLvl != level)    return false;
                }
            }
            
            if(node->left){
                q.push({node->left, level+1});
            }
            if(node->right){
                q.push({node->right, level+1});
            }
        }
        return true;
    }

int main()
{
    
    return 0;
}