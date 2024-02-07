#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left, * right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// O(N)
    Node* findLCA(Node* root, int a, int b){
        if(root == NULL)    return NULL;
        if(root->data == a || root->data == b)  return root;
        
        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);
        
        if(left == NULL){
            if(right == NULL)  return NULL;
            
            return right;
        }
        else{
            if(right == NULL)  return left;
            // when left and right both are non-zero.
            return root;
        }
    }
    
    // level order traversal nothing extra. 
    // O(N)
    int findDistLca(Node* root, int key){
        
        if(root->data == key)   return 0;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(node->data == key)   return dist;
            
            if(node->left){
                q.push({node->left, dist+1});
            }
            if(node->right){
                q.push({node->right, dist+1});
            }
        }
        return -1;
    }
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        if(root == NULL) return NULL;
        
        Node* lca = findLCA(root, a, b);
        int dista = 0, distb = 0; // dista -> distance of a from lca, distb -> ........

        dista = findDistLca(lca, a);
        distb = findDistLca(lca, b);
        
        return dista + distb;
    }

int main()
{
    
    return 0;
}