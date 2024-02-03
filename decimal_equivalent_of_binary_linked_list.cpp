#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

    int mod = 1e9+7;
    // Should return decimal equivalent modulo 1000000007 of binary linked list 
    long long unsigned int decimalValue(Node *head)
    {
        
        // method 1 -> 
        if(head == NULL)    return 0;
        
        long long unsigned int ans = 0;
        while(head != NULL){
            ans <<= 1;
            ans =(ans + head -> data ) % mod;
            head = head -> next;
        }
        
        return ans % mod;
        
        // method 2 -> you can reverse the linked list to do so.
    }

int main()
{
    
    return 0;
}