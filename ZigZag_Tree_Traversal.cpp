#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// code ->
// t.c = O(number of nodes)    ||  s.c = O(number of nodes)
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
// doing the level order traversal but in zig zag fashion
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	
    	bool LTR = true;    // LTR -> left to right
    	while(!q.empty()){
    	    
    	    int size = q.size();
    	    vector<int> temp(size, 0);
    	    
    	    for(int i=0; i<size; i++){
    	        
    	        Node* node = q.front();
    	        q.pop();
// now where to push this node in temp vector, means from start to end or from end to start.
// this is the only trick / important / understanding line of the code.
    	        int idx = LTR ? i : (size-i-1);
    	        
    	        temp[idx] = node->data;
    	        
    	        if(node->left)  q.push(node->left);
    	        if(node->right) q.push(node->right);
    	    }
    	    
    	    LTR = !LTR;
    	    for(auto it:temp)   ans.push_back(it);
    	}
    	
    	return ans;
    }
};

int main()
{

    return 0;
}