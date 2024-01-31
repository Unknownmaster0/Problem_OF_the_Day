#include<iostream>
#include<vector>
using namespace std;


struct TrieNode {
    struct TrieNode *children[26];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < 26; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            struct TrieNode* node = root;
            
            for(int i = 0; i<key.size(); i++)
            {
                char ch = key[i];
                
                if(node->children[ch-'a'] == NULL){
                    
                    struct TrieNode* ref = getNode();
                    node->children[ch-'a'] = ref;
                }
                node = node->children[ch-'a'];
            }
            // set the leaf node as true;
            node->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            struct TrieNode* node = root;
            
            for(int i = 0; i<key.size(); i++){
                char ch = key[i];
                
                if(node->children[ch-'a'] == NULL) return false;
                
                node = node->children[ch-'a'];
            }
            
            if(node->isLeaf)    return true;
            return false;
        }

int main()
{
    
    return 0;
}