#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://leetcode.com/problems/reverse-linked-list/?envType=daily-question&envId=2024-03-21

// Code->
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // using two nodes prev and curr to iterate the linked list.
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head;

        while( curr != NULL )
        {
            // using the forward node to store the forward address of the node.
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
};


int main()
{
    
    return 0;
}