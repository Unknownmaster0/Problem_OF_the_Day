#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/merge-in-between-linked-lists/description/

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

// t.c = O(n1 + n2) [n1 -> no. of nodes in list1, n2-> no. of nodes in list2]
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // step 1-> remove the ath to bth node.
        ListNode* head = list1, *start = NULL, *end = NULL;
        int length = 0;

// t.c = O(number of nodes in list1)
        while(head != NULL){

            if(start != NULL && end != NULL)    break;
            if(length == a-1) start = head;
            if(length == b) end = head;
            length ++;
            head = head->next;
        }

        // removing the nodes of the list1.
        ListNode* forward = end->next;
        start->next = forward;
        end->next = NULL;
        end = forward;

        // merging the node of the list2 at the location
        start->next = list2;
// t.c = O(number of nodes in list 2)
        while(list2->next != NULL){
            list2 = list2->next;
        }
        list2->next = end;

        return list1;
    }
};

int main()
{

    return 0;
}