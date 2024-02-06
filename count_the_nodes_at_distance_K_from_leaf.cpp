#include <iostream>
#include <vector>
#include <set>
using namespace std;

// problem link ->https://www.geeksforgeeks.org/problems/node-at-distance/1

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/*Approach -> AT each node we are storing it into the path vector if it is not null.
              Then we check if the current node is leaf node or not.
              if it is leaf node, then we check if the (kth node from the leaf does exist or not.) [path.size()-1-k] = gives idx of kth node in path vector.
              if idx > -1, means node exist then we push into the set.

              and call the left and right recursion simply.

              But at time of going back, simply do the pop_back operation in path vector.
*/

// time complexity -> O(N) [N = number of nodes]
void countNodes(Node *root, int k, vector<Node *> &path, set<Node *> &st)
{
    if (root == NULL)
        return;

    path.push_back(root);
    if (root->left == NULL && root->right == NULL)
    {
        int idx = path.size() - 1 - k;
        if (idx > -1)
        {
            st.insert(path[idx]);
        }
    }

    countNodes(root->left, k, path, st);
    countNodes(root->right, k, path, st);

    path.pop_back();
}

// Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node *root, int k)
{
    /***************Important************/
    // here the data type of set and vector should be (Node*) not "int" as the node->data of various node may be same.
    // then in that case you get wrong answer.
    // whereas when you store the Node* or node then you will get the unique node irespective they have same value.
    set<Node *> st;
    vector<Node *> path;
    countNodes(root, k, path, st);

    return st.size();
}

int main()
{

    return 0;
}