#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;


// code -> 

struct Node{
    int data;
    Node* left, *right;

    Node(){
        data = 0;
        left = NULL, right = NULL;
    }

    Node(int data){
        this->data = data;
        left = NULL, right = NULL;
    }
};

class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        
        map<int,int> mp; // diagonal level, sum
        
        queue<pair<int,Node*>> q;
        q.push(make_pair(0,root));
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                
                Node* node = q.front().second;
                int lvl = q.front().first;
                
                q.pop();
                
                if(mp.find(lvl) != mp.end()){
                    
                    mp[lvl] += node->data;
                }
                else{
                    mp[lvl] = node->data;
                }
                
                if(node->left){
                    q.push(make_pair(lvl+1, node->left));
                }
                if(node->right){
                    q.push(make_pair(lvl, node->right));
                }
            }
        }
        
        vector<int> ans;
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

int main()
{
    
    return 0;
}